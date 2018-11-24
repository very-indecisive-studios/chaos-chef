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
}

Texture * ResourceManager::GetTexture(std::string textureName) 
{
	auto itr = textureResourceMap.find(textureName);
	
	if (itr != textureResourceMap.end()) 
	{
		return itr->second;
	}
	else 
	{
		Texture *loadedTexture = Context::Get()->GetGraphicsRenderer()->LoadTextureFromFile(textureName);

		textureResourceMap[textureName] = loadedTexture;

		return loadedTexture;
	}
}