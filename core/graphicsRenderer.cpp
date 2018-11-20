#include "graphicsRenderer.h"
#include "gameException.h"

void core::GraphicsRenderer::InitParamsD3D() {
	// Initialize D3D presentation params
	ZeroMemory(&paramsD3D, sizeof(paramsD3D));              // fill the structure with 0

	paramsD3D.BackBufferWidth = width;
	paramsD3D.BackBufferHeight = height;
	if (fullscreen) // if fullscreen
		paramsD3D.BackBufferFormat = D3DFMT_X8R8G8B8;  // 24 bit color
	else
		paramsD3D.BackBufferFormat = D3DFMT_UNKNOWN;   // use desktop setting
	paramsD3D.BackBufferCount = 1;
	paramsD3D.SwapEffect = D3DSWAPEFFECT_DISCARD;
	paramsD3D.hDeviceWindow = hwnd;
	paramsD3D.Windowed = (!fullscreen);
	paramsD3D.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}

HRESULT core::GraphicsRenderer::SwapBuffer()
{
	HRESULT result = E_FAIL;

	result = deviceD3D->Present(NULL, NULL, NULL, NULL);

	return result;
}

void core::GraphicsRenderer::ReleaseAll()
{
	spriteD3D->Release();
	deviceD3D->Release();
	d3d->Release();

	ClearAllSpriteDrawJobs();
}

HRESULT core::GraphicsRenderer::Reset()
{
	HRESULT result = E_FAIL;    // default to fail, replace on success

	InitParamsD3D();                        // init D3D presentation parameters

	result = deviceD3D->Reset(&paramsD3D);   // attempt to reset graphics device

	return result;
}

core::GraphicsRenderer::GraphicsRenderer()
{
	deviceD3D = NULL;
	spriteD3D = NULL;
	d3d = NULL;

	spriteDrawJobs = new std::vector<DrawSpriteJob *>;
}

core::GraphicsRenderer::~GraphicsRenderer()
{
	ReleaseAll();

	delete spriteDrawJobs;
}

HRESULT core::GraphicsRenderer::Initialize(HWND hwnd, int width, int height, bool fullscreen)
{
	this->hwnd = hwnd;
	this->width = width;
	this->height = height;
	this->fullscreen = fullscreen;

	HRESULT result = E_FAIL;

	// Initialize D3D.
	d3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (d3d == NULL) 
	{
		return result;
	}

	// Initialize D3D presentation params.
	InitParamsD3D();

	if (fullscreen) 
	{
		UINT modes = d3d->GetAdapterModeCount(
			D3DADAPTER_DEFAULT,
			paramsD3D.BackBufferFormat
		);

		for (UINT i = 0; i < modes; i++)
		{
			result = d3d->EnumAdapterModes(
				D3DADAPTER_DEFAULT,
				paramsD3D.BackBufferFormat,
				i,
				&dModeD3D
			);

			if (
				SUCCEEDED(result) &&
				dModeD3D.Height == paramsD3D.BackBufferHeight &&
				dModeD3D.Width == paramsD3D.BackBufferWidth &&
				dModeD3D.RefreshRate >= paramsD3D.FullScreen_RefreshRateInHz
			) 
			{
				
				paramsD3D.FullScreen_RefreshRateInHz = dModeD3D.RefreshRate;
			}
		}
	}

	// Determine if graphics card supports harware texturing and lighting and vertex shaders
	D3DCAPS9 caps;
	DWORD behavior;
	result = d3d->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);
	// If device doesn't support HW T&L or doesn't support 1.1 vertex 
	// shaders in hardware, then switch to software vertex processing.
	if (
		(caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT) == 0 ||
		caps.VertexShaderVersion < D3DVS_VERSION(1, 1)
	)
		behavior = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  // use software only processing
	else
		behavior = D3DCREATE_HARDWARE_VERTEXPROCESSING;  // use hardware only processing

	// Create D3D device.
	result = d3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hwnd,
		behavior,
		&paramsD3D,
		&deviceD3D
	);

	if (FAILED(result)) 
	{
		return result;
	}

	// Create D3D sprite.
	result = D3DXCreateSprite(deviceD3D, &spriteD3D);

	return result;
}

HRESULT core::GraphicsRenderer::HandleLostDevice()
{
	HRESULT result = E_FAIL;

	if (deviceD3D == NULL)
	{
		return result;
	}

	result = deviceD3D->TestCooperativeLevel();
	
	if (FAILED(result))                  // if graphics device is not in a valid state
	{
		// if the device is lost and not available for reset
		if (result == D3DERR_DEVICELOST)
		{
			Sleep(100);             // yield cpu time (100 mili-seconds)
			return result;
		}
		// the device was lost but is now available for reset
		else if (result == D3DERR_DEVICENOTRESET)
		{
			ReleaseAll();
			result = Reset(); // attempt to reset graphics device
			
			if (FAILED(result))          // if reset failed
				return result;
		}
		else
			return result;                 // other device error
	}

	return result;
}

HRESULT core::GraphicsRenderer::Render() {
	HRESULT result = E_FAIL;

	if (deviceD3D == nullptr || spriteD3D == nullptr) {
		return result;
	}
	
	try {
		core::ThrowIfFailed(deviceD3D->Clear(0, NULL, D3DCLEAR_TARGET, BACK_COLOUR, 1.0F, 0));

		core::ThrowIfFailed(deviceD3D->BeginScene());
			core::ThrowIfFailed(spriteD3D->Begin(D3DXSPRITE_ALPHABLEND));
				for (auto sprJob : *spriteDrawJobs) {
					// Find center of sprite
					D3DXVECTOR2 spriteCenter = D3DXVECTOR2(
						(float)(sprJob->sprite->GetWidth() / 2 * sprJob->sprite->GetScale()),
						(float)(sprJob->sprite->GetHeight() / 2 * sprJob->sprite->GetScale())
					);
					D3DXVECTOR2 translate = D3DXVECTOR2((float) sprJob->pos.x, (float) sprJob->pos.y);
					D3DXVECTOR2 scaling(sprJob->sprite->GetScale(), sprJob->sprite->GetScale());

					D3DXMATRIX matrix;
					D3DXMatrixTransformation2D(
						&matrix,                // the matrix
						NULL,                   // keep origin at top left when scaling
						0.0f,                   // no scaling rotation
						&scaling,               // scale amount
						&spriteCenter,          // rotation center
						0,						// rotation angle
						&translate				// X,Y location
					);


					spriteD3D->SetTransform(&matrix);

					spriteD3D->Draw(
						sprJob->sprite->GetTexture()->GetTextureD3D(), 
						sprJob->sprite->GetDrawingArea(), 
						NULL, 
						NULL, 
						0xFFFFFFFF
					);
				}
			core::ThrowIfFailed(spriteD3D->End());

			ClearAllSpriteDrawJobs();
		core::ThrowIfFailed(deviceD3D->EndScene());

		core::ThrowIfFailed(SwapBuffer());

		result = S_OK;
	}
	catch (GameException e) {
		return result;
	}

	return result;
}

core::Texture * core::GraphicsRenderer::LoadTextureFromFile(std::string fileName) 
{
	HRESULT result = E_FAIL;

	// Get image info from file.
	D3DXIMAGE_INFO imageInfo;
	result = D3DXGetImageInfoFromFile(fileName.c_str(), &imageInfo);
	core::ThrowIfFailed(result);

	// Create the new texture by loading from file.
	LPDIRECT3DTEXTURE9 textureD3D = NULL;
	result = D3DXCreateTextureFromFileEx(
		deviceD3D,          //3D device
		fileName.c_str(),	//image filename
		imageInfo.Width,    //texture width
		imageInfo.Height,   //texture height
		1,                  //mip-map levels (1 for no chain)
		0,                  //usage
		D3DFMT_UNKNOWN,     //surface format (default)
		D3DPOOL_DEFAULT,    //memory class for the texture
		D3DX_DEFAULT,       //image filter
		D3DX_DEFAULT,       //mip filter
		0xFF000000,         //color key for transparency
		&imageInfo,         //bitmap file info (from loaded file)
		NULL,               //color palette
		&textureD3D			//destination texture
	);

	core::ThrowIfFailed(result);

	return new Texture(textureD3D, imageInfo.Width, imageInfo.Height);
}

void core::GraphicsRenderer::QueueSpriteDrawJob(DrawSpriteJob *job) {
	spriteDrawJobs->push_back(job);
}

void core::GraphicsRenderer::ClearAllSpriteDrawJobs() {
	for (auto sprJob : *spriteDrawJobs) 
	{
		delete sprJob;
		sprJob = nullptr;
	}

	spriteDrawJobs->clear();
}