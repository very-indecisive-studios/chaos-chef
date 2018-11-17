#pragma once

#include "math.h"
#include "texture.h"
#include <string>

namespace core {
	class Sprite {
	private:
		Texture *texture;
		int height;
		int width;
		int scale;
	public:
		Sprite(Texture *&texture, int scale = 1);
		~Sprite();
		void Draw(Vector2 position);
		int GetHeight();
		int GetWidth();
		int GetScale();
		Texture * GetTexture();

		static Sprite * Create(const std::string &textureName, int scale = 1);
	};
}