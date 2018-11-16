#pragma once

#include "graphicsRenderer.h"
#include "resourceManager.h"

namespace core {
	class Context {
	private:
		core::GraphicsRenderer *graphicsRenderer;
		core::ResourceManager  *resourceManager;

		Context();
		~Context();
		
		static Context * instance;
	public:
		core::GraphicsRenderer *const GetGraphicsRenderer();
		core::ResourceManager *const GetResourceManager();
		
		static void ReleaseAll();

		static Context *const Get();
		static void Initialize();
	};
}