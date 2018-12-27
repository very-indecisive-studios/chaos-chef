#include <iostream>
#include "InstructionScene.h"
#include "context.h"
#include "constants.h"

InstructionScene::InstructionScene()
	: Scene(SceneType::MAIN_MENU)
{
	instructions = Sprite::Create(INSTRUCTION_IMAGE, 0);
}

InstructionScene::~InstructionScene()
{
	delete instructions;
}

void InstructionScene::Update(float deltaTime)
{
	instructions->Draw(Vector2(0, 0));

	if (Context::Get()->GetInputManager()->IsKeyDown(VK_ESCAPE))
	{
		Context::Get()->GetSceneManager()->LoadMainMenuScene();
	}
}