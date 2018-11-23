#pragma once

#include "math.h"
#include "texture.h"
#include <string>

namespace core
{
	typedef RECT DrawingArea;

	typedef uint8_t SpriteLayer;
	const SpriteLayer LAYER_BACKGROUND	= 1 << 0;
	const SpriteLayer LAYER_ENTITIES	= 1 << 2;

	class Sprite 
	{
	protected:
		int height;
		int width;
		DrawingArea drawingArea;
	private:
		int scale;
		Texture *texture;
		SpriteLayer layer;
	public:
		Sprite(Texture *texture, SpriteLayer layer, int scale = 1);
		void Draw(Vector2 position);
		
		Texture * GetTexture();
		int GetHeight();
		int GetWidth();
		int GetScale();
		DrawingArea * GetDrawingArea();
		SpriteLayer GetLayer();

		static Sprite * Create(const std::string &textureName, SpriteLayer layer, int scale = 1);
	};
}