#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <string>
#include <vector>
#include "texture.h"
#include "core/math.h"
#include "core/sprites/sprite.h"

// Color defines
#define COLOR_ARGB DWORD
#define SETCOLOR_ARGB(a,r,g,b) \
    ((COLOR_ARGB)((((a)&0xff)<<24)|(((r)&0xff)<<16)|(((g)&0xff)<<8)|((b)&0xff)))

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
	COLOR_ARGB  backColor;      // background color

	const D3DCOLOR BACK_COLOUR = 0xFF000000;

	void InitParamsD3D();

	HRESULT SwapBuffer();

	HRESULT Reset();

	void ClearAllSpriteDrawJobs();

	// Text
	LPD3DXFONT dxFont;
	D3DXMATRIX matrix;
	float angle;
	COLOR_ARGB color;
	RECT fontRect;

public:
	GraphicsRenderer();

	~GraphicsRenderer();

	HRESULT Initialize(HWND hwnd, int width, int height, bool fullscreen);
		
	void QueueSpriteDrawJob(DrawSpriteJob *job);

	HRESULT HandleLostDevice();

	HRESULT Render();

	Texture * LoadTextureFromFile(std::string fileName);

	void ReleaseAll();

	void SetBackColor(COLOR_ARGB c) { backColor = c; }

	// Text
	bool InitializeText(int height, bool bold, bool italic, const std::string &fontName);
	int Print(const std::string &str, int x, int y);
	int Print(const std::string &str, RECT &rect, UINT format);
	float GetDegrees();
	float GetRadians();
	float GetFontColor();
	void SetDegrees(float deg);
	void SetRadians(float rad);
	void SetFontColor(COLOR_ARGB c);
	void OnResetDevice();
	void OnLostDevice();
};
