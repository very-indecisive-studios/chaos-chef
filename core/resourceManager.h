#pragma once

#include <string>
#include <map>
#include "texture.h"

namespace core {
	class ResourceManager {
	private:
		std::map<std::string, core::Texture *> *textureResourceMap;
	public:
		ResourceManager();
		~ResourceManager();

		core::Texture * GetTexture(std::string textureName);
	};
}