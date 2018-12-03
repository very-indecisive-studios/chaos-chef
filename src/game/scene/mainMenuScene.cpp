#include <iostream>
#include "mainMenuScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

MainMenuScene::MainMenuScene() : Scene(SceneType::MAIN_MENU){ }

MainMenuScene::~MainMenuScene()
{
	End();
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

		}
		else if (pointedButton == bodyText3) //transition to leaderboard scene
		{
			Context::Get()->GetSceneManager()->LoadLeaderboardScene();
		}
		else if (pointedButton == bodyText4) //transition to credits menu
		{

		}
	}
}

void MainMenuScene::Begin()
{
	topText = Text::Create("CHAOS CHEF", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText1 = Text::Create("PLAY", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText2 = Text::Create("HOW TO PLAY", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText3 = Text::Create("LEADERBOARD", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText4 = Text::Create("CREDITS", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	buttons.push_back(bodyText1);
	buttons.push_back(bodyText2);
	buttons.push_back(bodyText3);
	buttons.push_back(bodyText4);
	pointedButton = bodyText1;
}

void MainMenuScene::Update(float deltaTime)
{
	int count = 0;
	topText->Draw(Vector2(0, 0));

	for (Text *button : buttons) 
	{
		button->Draw(Vector2(0, (GAME_HEIGHT*0.5f - (buttons.size() / 2 * FONT_SIZE)) + (FONT_SIZE * count)));
		count++;
	}

	ManeuverMenu();
	CheckButtonClick();
}

void MainMenuScene::End() {

}