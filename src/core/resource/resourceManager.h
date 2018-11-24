#pragma once

#include <string>
#include <map>
#include "core/graphics/texture.h"

class ResourceManager 
{
private:
	std::map<std::string, Texture *> textureResourceMap;
public:
	ResourceManager();
	~ResourceManager();

	Texture * GetTexture(std::string textureName);
};
