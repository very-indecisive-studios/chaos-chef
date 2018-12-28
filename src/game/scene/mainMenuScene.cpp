#include <iostream>
#include "mainMenuScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

MainMenuScene::MainMenuScene() 
	: Scene(SceneType::MAIN_MENU)
{
	background = Sprite::Create(BACKGROUND_IMAGE_MAIN_MENU, 0);

	bodyText1 = Text::Create("PLAY", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText2 = Text::Create("HOW TO PLAY", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText3 = Text::Create("LEADERBOARD", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);

	buttons.push_back(bodyText1);
	buttons.push_back(bodyText2);
	buttons.push_back(bodyText3);

	pointedButton = bodyText1;
}

MainMenuScene::~MainMenuScene()
{
	for (Text *text : buttons)
	{
		delete text;
	}

	delete background;
}

void MainMenuScene::ManeuverMenu() 
{
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_DOWN))
	{
		if (pointedButtonPos < buttons.size() - 1) 
		{
			pointedButtonPos += 1;
			Context::Get()->GetInputManager()->ClearAll();
		}
	}

	if (Context::Get()->GetInputManager()->IsKeyDown(VK_UP))
	{
		if (pointedButtonPos > 0)
		{
			pointedButtonPos -= 1;
			Context::Get()->GetInputManager()->ClearAll();
		}
	}
	pointedButton->SetColor(FONT_COLOR_WHITE);
	pointedButton = buttons.at(pointedButtonPos);
	pointedButton->SetColor(FONT_COLOR_RED);
}

void MainMenuScene::CheckButtonClick()
{
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN)) 
	{
		Context::Get()->GetInputManager()->ClearAll();
		if (pointedButton == bodyText1) //transition to select level scene
		{
			Context::Get()->GetSceneManager()->LoadSelectLevelScene();
		}
		else if (pointedButton == bodyText2) //transition to instruction menu
		{
			Context::Get()->GetSceneManager()->LoadInstructionScene();
		}
		else if (pointedButton == bodyText3) //transition to leaderboard scene
		{
			Context::Get()->GetSceneManager()->LoadPreLeaderboardScene();
		}
	}
}

void MainMenuScene::Update(float deltaTime)
{
	ManeuverMenu();
	CheckButtonClick();

	int count = 0;
	background->Draw(Vector2(0, 0));

	for (Text *button : buttons) 
	{
		button->Draw(Vector2(0, 75 + (GAME_HEIGHT*0.5f - (buttons.size() / 2 * FONT_SIZE)) + (FONT_SIZE * count)));
		count++;
	}
}
