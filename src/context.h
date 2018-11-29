#pragma once

#include "core/graphics/graphicsRenderer.h"
#include "core/resource/resourceManager.h"
#include "core/input/inputManager.h"
#include "game/scene/sceneManager.h"
#include "game.h"

class Context 
{
private:
	GraphicsRenderer	*graphicsRenderer;
	ResourceManager		*resourceManager;
	InputManager		*inputManager;
	SceneManager		*sceneManager;
	Game				*game;

	Context();
	~Context();
		
	static Context * instance;
public:
	GraphicsRenderer	*const GetGraphicsRenderer();
	ResourceManager		*const GetResourceManager();
	InputManager		*const GetInputManager();
	SceneManager		*const GetSceneManager();
	Game				*const GetGame();

	static void ReleaseAll();

	static Context *const Get();
	static void Initialize();
};
