#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include <vector>
#include "texture.h"
#include "core/math.h"
#include "core/sprites/sprite.h"
#include "core/text/text.h"

enum class DrawJobType { SPRITE, TEXT };

struct DrawJob
{
	DrawJobType type;
	Vector2 pos;
	uint8_t layer;

	DrawJob(DrawJobType type, Vector2 pos, uint8_t layer) 
		: type(type), pos(pos), layer(layer) { }
};

struct DrawSpriteJob : public DrawJob
{
	Sprite *sprite;

	DrawSpriteJob(Sprite *sprite, Vector2 pos, uint8_t layer) 
		: DrawJob(DrawJobType::SPRITE, pos, layer), sprite(sprite)
	{ }
};

struct DrawTextJob : public DrawJob
{
	Text *text;

	DrawTextJob(Text *text, Vector2 pos, uint8_t layer)
		: DrawJob(DrawJobType::TEXT, pos, layer), text(text)
	{ }
};

class GraphicsRenderer 
{
private:
	// Sprite draw queue.
	std::vector<DrawJob *> drawJobs;

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

	void ClearAllDrawJobs();
public:
	GraphicsRenderer();

	~GraphicsRenderer();

	HRESULT Initialize(HWND hwnd, int width, int height, bool fullscreen);
		
	void QueueDrawJob(DrawJob *job);

	HRESULT HandleLostDevice();

	HRESULT Render();

	Texture * LoadTextureFromFile(std::string fileName);

	Font LoadFont(const std::string& fontName, int height, UINT weight, BOOL italic);

	void ReleaseAll();
};
