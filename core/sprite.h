#pragma once

#include "math.h"
#include "texture.h"
#include <string>

namespace core {
	typedef RECT DrawingArea;

	class Sprite {
	protected:
		int height;
		int width;
		DrawingArea drawingArea;
	private:
		int scale;
		Texture *texture;
	public:
		Sprite(Texture *texture, int scale = 1);
		void Draw(Vector2 position);
		Texture * GetTexture();
		int GetHeight();
		int GetWidth();
		int GetScale();
		DrawingArea * GetDrawingArea();

		static Sprite * Create(const std::string &textureName, int scale = 1);
	};
}