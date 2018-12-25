#include "resourceManager.h"
#include "context.h"

ResourceManager::ResourceManager() { }

ResourceManager::~ResourceManager() 
{
	// Deallocate all textures.
	for (const auto& pair : textureResourceMap) 
	{
		delete pair.second;
	}

	// Deallocate all fonts.
	for (const auto& font : fontResourceList)
	{
		delete font;
	}
}

Texture * ResourceManager::GetTexture(const std::string &textureName)
{
	auto itr = textureResourceMap.find(textureName);

	if (itr != textureResourceMap.end())
	{
		return itr->second;
	}

	Texture *loadedTexture = Context::Get()->GetGraphicsRenderer()->LoadTextureFromFile(textureName);

	textureResourceMap[textureName] = loadedTexture;

	return loadedTexture;
}


Font * ResourceManager::GetFont(const std::string& fontName, int height, UINT weight, BOOL italic)
{
	for (const auto font : fontResourceList)
	{
		if (
			font->GetFontName() == fontName &&
			font->GetHeight() == height && 
			font->GetWeight() == weight && 
			font->GetItalic() == italic)
		{
			return font;
		}
	}

	Font *loadedFont = Context::Get()->GetGraphicsRenderer()->LoadFont(fontName, height, weight, italic);

	fontResourceList.push_back(loadedFont);

	return loadedFont;
}
