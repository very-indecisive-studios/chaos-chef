#include "context.h"

core::Context::Context()
{
	graphicsRenderer	= new GraphicsRenderer();
	resourceManager		= new ResourceManager();
	inputManager		= new InputManager();
}

core::Context::~Context()
{
	delete graphicsRenderer;
	graphicsRenderer = nullptr;

	delete resourceManager;
	resourceManager = nullptr;

	delete inputManager;
	inputManager = nullptr;
}

core::GraphicsRenderer *const core::Context::GetGraphicsRenderer()
{
	return graphicsRenderer;
}

core::ResourceManager *const core::Context::GetResourceManager()
{
	return resourceManager;
}

core::InputManager *const core::Context::GetInputManager()
{
	return inputManager;
}

/*
	Static variables.
*/

core::Context * core::Context::instance = nullptr;

core::Context *const core::Context::Get() {
	return instance;
}

void core::Context::Initialize() {
	if (instance == nullptr) {
		instance = new Context();
	}
}

void core::Context::ReleaseAll() 
{
	delete instance;
	instance = nullptr;
}
