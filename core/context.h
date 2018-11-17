#pragma once

#include "graphicsRenderer.h"
#include "resourceManager.h"
#include "inputManager.h"

namespace core {
	class Context {
	private:
		core::GraphicsRenderer *graphicsRenderer;
		core::ResourceManager  *resourceManager;
		core::InputManager *inputManager;

		Context();
		~Context();
		
		static Context * instance;
	public:
		core::GraphicsRenderer *const GetGraphicsRenderer();
		core::ResourceManager *const GetResourceManager();
		core::InputManager *const GetInputManager();

		static void ReleaseAll();

		static Context *const Get();
		static void Initialize();
	};
}