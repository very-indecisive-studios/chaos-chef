#include <iostream>
#include "InstructionScene.h"
#include "context.h"
#include "constants.h"

InstructionScene::InstructionScene()
	: Scene(SceneType::MAIN_MENU)
{
	text = Text::Create("", FONT_TYPE, FONT_COLOR_BLACK, FONT_SIZE, 100, false, false);
	smaller_text = Text::Create("", FONT_TYPE, FONT_COLOR_BLACK, FONT_SIZE-4, 100, false, false);

	instructions_1 = Sprite::Create(INSTRUCTION_IMAGE_1, 0);
	instructions_2 = Sprite::Create(INSTRUCTION_IMAGE_2, 0);
	instructions_3 = Sprite::Create(INSTRUCTION_IMAGE_3, 0);
	instructions_4 = Sprite::Create(INSTRUCTION_IMAGE_4, 0);
	instructions_5 = Sprite::Create(INSTRUCTION_IMAGE_5, 0);
	instructions_6 = Sprite::Create(INSTRUCTION_IMAGE_6, 0);

	list_of_instructions.push_back(instructions_1);
	list_of_instructions.push_back(instructions_2);
	list_of_instructions.push_back(instructions_3);
	list_of_instructions.push_back(instructions_4);
	list_of_instructions.push_back(instructions_5);
	list_of_instructions.push_back(instructions_6);
}

InstructionScene::~InstructionScene()
{
	for (Sprite *sprite : list_of_instructions)
	{
		delete sprite;
	}
	
	delete text;
}

void InstructionScene::Update(float deltaTime)
{
	if (currentNo == 1) 
	{
		instructions_1->Draw(Vector2(0, 0));
		text->SetText("OBJECTIVE - COMPLETE ORDERS TO OBTAIN POINTS\n\n\n3 STEPS TO COMPLETE ORDERS\n1. Collect ingredient(s) from dispensers\n2. Cross the road and avoid oncoming traffic\n3. Serve dish at counter according to order no.\n\n\n\nPress <ENTER> to continue");
		text->Draw(Vector2(0,FONT_SIZE * 4));
	}
	else if (currentNo == 2)
	{
		instructions_2->Draw(Vector2(0, 0));
		smaller_text->SetText("HAND\n Displays current ingredients on hand\n\n\nPress <ENTER> to continue");
		smaller_text->Draw(Vector2(0, FONT_SIZE * 7));
	}
	else if (currentNo == 3)
	{
		instructions_3->Draw(Vector2(0, 0));
		smaller_text->SetText("ORDERS\n Each order has different ingredients\n Serve the order before time runs out!\n\nPress <ENTER> to continue");
		smaller_text->Draw(Vector2(0, FONT_SIZE * 7));
	}
	else if (currentNo == 4)
	{
		instructions_4->Draw(Vector2(0, 0));
		smaller_text->SetText("COUNTER\n Serve order to the correct counter no.\n based on the order no.\n\nPress <ENTER> to continue");
		smaller_text->Draw(Vector2(0, FONT_SIZE * 7));
	}
	else if (currentNo == 5)
	{
		instructions_5->Draw(Vector2(0, 0));
		smaller_text->SetText("DISPENSERS\n Collect ingredients here using <SPACE>\n\n\nPress <ENTER> to continue");
		smaller_text->Draw(Vector2(0, FONT_SIZE * 7));
	}
	else if (currentNo == 6)
	{
		instructions_6->Draw(Vector2(0, 0));
		smaller_text->SetText("TRASHBIN\n Remove current ingredients on hand\n using <SPACE> (-20 points)\n\n Press <ENTER> to continue");
		smaller_text->Draw(Vector2(0, FONT_SIZE * 7));
	}
	else if (currentNo == 7) 
	{
		instructions_1->Draw(Vector2(0, 0));
		text->SetText("READY TO PLAY?\n\n\nPress <ENTER> to start\n\nPress <BACKSPACE> to go back to instructions");
		text->Draw(Vector2(0, FONT_SIZE * 4));
		if (Context::Get()->GetInputManager()->IsKeyDown(VK_BACK))
		{
			Context::Get()->GetInputManager()->ClearAll();
			currentNo = 1;
		}
	}
	else
	{
		Context::Get()->GetSceneManager()->LoadSelectLevelScene();
	}

	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN))
	{
		Context::Get()->GetInputManager()->ClearAll();
		currentNo++;
	}
}