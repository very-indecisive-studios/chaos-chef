#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include "texture.h"
#include "sprite.h"
#include <vector>

namespace core 
{
	struct DrawSpriteJob 
	{
		Sprite *sprite;
		Vector2 pos;
	};

	class GraphicsRenderer 
	{
	private:
		// Sprite draw queue.
		std::vector<DrawSpriteJob *> spriteDrawJobs;

		// DirectX 3D pointers.
		LPDIRECT3DDEVICE9	deviceD3D;
		LPDIRECT3D9			d3d;
		LPD3DXSPRITE		spriteD3D;

		// DirectX 3D properties.
		D3DPRESENT_PARAMETERS	paramsD3D;
		D3DDISPLAYMODE			dModeD3D;

		// Application window properties.
		HWND        hwnd;
		bool        fullscreen;
		int         width;
		int         height;

		const D3DCOLOR BACK_COLOUR = 0xFF000000;

		void InitParamsD3D();

		HRESULT SwapBuffer();

		HRESULT Reset();

		void ClearAllSpriteDrawJobs();

	public:
		GraphicsRenderer();

		~GraphicsRenderer();

		HRESULT Initialize(HWND hwnd, int width, int height, bool fullscreen);
		
		void QueueSpriteDrawJob(DrawSpriteJob *job);

		HRESULT HandleLostDevice();

		HRESULT Render();

		Texture * LoadTextureFromFile(std::string fileName);

		void ReleaseAll();
	};
}