#pragma once

#include "graphicsRenderer.h"
#include "resourceManager.h"
#include "game.h"
#include "inputManager.h"

namespace core {
	class Context {
	private:
		core::GraphicsRenderer	*graphicsRenderer;
		core::ResourceManager	*resourceManager;
		core::InputManager		*inputManager;
		core::Game				*game;

		Context();
		~Context();
		
		static Context * instance;
	public:
		core::GraphicsRenderer	*const GetGraphicsRenderer();
		core::ResourceManager	*const GetResourceManager();
		core::InputManager		*const GetInputManager();
		core::Game				*const GetGame();

		static void ReleaseAll();

		static Context *const Get();
		static void Initialize();
	};
}