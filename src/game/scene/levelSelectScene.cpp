#include <iostream>
#include "levelSelectScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

LevelSelectScene::LevelSelectScene() : Scene(SceneType::LEVEL_SELECT){ }

LevelSelectScene::~LevelSelectScene()
{
	End();
}

void LevelSelectScene::ManeuverMenu()
{
	if (delayPress == true)
	{
		Context::Get()->GetInputManager()->ClearAll();
		delayPress = false;
	}

	if (Context::Get()->GetInputManager()->IsKeyDown(VK_DOWN))
	{
		if (pointedButtonPos < buttons.size() - 1)
		{
			pointedButtonPos += 1;
			delayPress = true;
		}
	}

	if (Context::Get()->GetInputManager()->IsKeyDown(VK_UP))
	{
		if (pointedButtonPos > 0)
		{
			pointedButtonPos -= 1;
			delayPress = true;
		}
	}
	pointedButton->SetColor(FONT_COLOR_WHITE);
	pointedButton = buttons.at(pointedButtonPos);
	pointedButton->SetColor(FONT_COLOR_RED);
}

void LevelSelectScene::CheckButtonClick()
{
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN))
	{
		Context::Get()->GetInputManager()->ClearAll();
		if (pointedButton == bodyText1) // Newbie - Fried Basket
		{
			Context::Get()->GetSceneManager()->LoadGameScene();
		}
		else if (pointedButton == bodyText2) // Easy - Sashimi + Sushi
		{
			Context::Get()->GetSceneManager()->LoadGameScene();
		}
		else if (pointedButton == bodyText3) // Medium - Pasta
		{
			Context::Get()->GetSceneManager()->LoadGameScene();
		}
		else if (pointedButton == bodyText4) // Hard - Pizza
		{
			Context::Get()->GetSceneManager()->LoadGameScene();
		}
	}
}

void LevelSelectScene::Begin()
{
	topText = Text::Create("Select a level", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText1 = Text::Create("Newbie - Fried Basket", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText2 = Text::Create("Easy - Sashimi + Sushi", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText3 = Text::Create("Medium - Pasta", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText4 = Text::Create("Hard - Pizza", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	buttons.push_back(bodyText1);
	buttons.push_back(bodyText2);
	buttons.push_back(bodyText3);
	buttons.push_back(bodyText4);
	pointedButton = bodyText1;
}

void LevelSelectScene::Update(float deltaTime)
{
	int count = 0;
	topText->Draw(Vector2(0, 0));
	
	for (Text *button : buttons)
	{
		button->Draw(Vector2(0, (GAME_HEIGHT*0.5f) + (FONT_SIZE * count)));
		count++;
	}

	ManeuverMenu();
	CheckButtonClick();
}

void LevelSelectScene::End() 
{

}