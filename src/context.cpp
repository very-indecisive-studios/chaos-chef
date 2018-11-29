#include "context.h"
#include "core/gameException.h"

Context::Context()
{
	graphicsRenderer	= new GraphicsRenderer();
	resourceManager		= new ResourceManager();
	inputManager		= new InputManager();
	sceneManager		= new SceneManager();
	game				= new Game();
}

Context::~Context()
{
	delete graphicsRenderer;
	delete resourceManager;
	delete inputManager;
	delete sceneManager;
	delete game;
}

GraphicsRenderer *const Context::GetGraphicsRenderer()
{
	return graphicsRenderer;
}

ResourceManager *const Context::GetResourceManager()
{
	return resourceManager;
}

InputManager *const Context::GetInputManager()
{
	return inputManager;
}

SceneManager *const Context::GetSceneManager()
{
	return sceneManager;
}

Game *const Context::GetGame()
{
	return game;
}

/*
	Static variables.
*/

Context * Context::instance = nullptr;

Context *const Context::Get() 
{
	return instance;
}

void Context::Initialize() 
{
	if (instance == nullptr) 
	{
		instance = new Context();
	}
}

void Context::ReleaseAll() 
{
	delete instance;
	instance = nullptr;
}
