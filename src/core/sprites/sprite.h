#pragma once

#include "core/math.h"
#include "core/graphics/texture.h"
#include <string>

typedef RECT DrawingArea;

class Sprite 
{
protected:
	int height;
	int width;
	DrawingArea drawingArea;
private:
	int scale;
	Texture *texture;
	uint8_t layer;
public:
	Sprite(Texture *texture, uint8_t layer, int scale = 1);
	void Draw(Vector2 position);
		
	Texture * GetTexture();
	int GetHeight();
	int GetWidth();
	int GetScale();
	DrawingArea * GetDrawingArea();
	uint8_t GetLayer();

	static Sprite * Create(const std::string &textureName, uint8_t layer, int scale = 1);
};
