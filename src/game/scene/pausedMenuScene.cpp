#include <iostream>
#include "pausedMenuScene.h"
#include "game/resources.h"

PausedMenuScene::PausedMenuScene() : Scene(SceneType::PAUSED_MENU)
{ }

PausedMenuScene::~PausedMenuScene()
{
	End();
}

void PausedMenuScene::Begin()
{

}

void PausedMenuScene::Update(float deltaTime)
{

}

void PausedMenuScene::End()
{

}