#include "resourceManager.h"
#include "context.h"

core::ResourceManager::ResourceManager() { }

core::ResourceManager::~ResourceManager() {
	// Deallocate all textures.
	for (const auto& pair : textureResourceMap) {
		delete pair.second;
	}
}

core::Texture * core::ResourceManager::GetTexture(std::string textureName) {
	auto itr = textureResourceMap.find(textureName);
	
	if (itr != textureResourceMap.end()) {
		return itr->second;
	}
	else {
		core::Texture *loadedTexture = core::Context::Get()->GetGraphicsRenderer()->LoadTextureFromFile(textureName);

		textureResourceMap[textureName] = loadedTexture;

		return loadedTexture;
	}
}