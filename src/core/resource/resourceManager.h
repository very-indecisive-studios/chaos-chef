#pragma once

#include <string>
#include <map>
#include "core/graphics/texture.h"
#include "core/graphics/font.h"
#include <vector>

class ResourceManager 
{
private:
	std::map<std::string, Texture *> textureResourceMap;
	std::vector<Font *> fontResourceList;
public:
	ResourceManager();
	~ResourceManager();

	Texture * GetTexture(const std::string &textureName);
	Font * GetFont(const std::string& fontName, int height, UINT weight, BOOL italic);
};
