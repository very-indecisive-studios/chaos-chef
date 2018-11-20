#pragma once

#include "math.h"
#include "texture.h"
#include <string>

namespace core {
	typedef RECT DrawingArea;

	class Sprite {
	private:
		Texture *texture;
		int height;
		int width;
		int scale;
		DrawingArea *drawingArea;
	public:
		Sprite(Texture *texture, int scale = 1);
		virtual ~Sprite();
		virtual void Draw(Vector2 position);
		Texture * GetTexture();
		int GetHeight();
		int GetWidth();
		int GetScale();
		DrawingArea * GetDrawingArea();

		static Sprite * Create(const std::string &textureName, int scale = 1);
	};
}