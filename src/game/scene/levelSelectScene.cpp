#include <iostream>
#include "levelSelectScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

LevelSelectScene::LevelSelectScene() 
	: Scene(SceneType::LEVEL_SELECT)
{
	background = Sprite::Create(BACKGROUND_IMAGE_OTHERS, 0);

	topText = Text::Create("Select a level", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);

	bodyText1 = Text::Create("Newbie - Fried Basket", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText2 = Text::Create("Easy - Sashimi + Sushi", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText3 = Text::Create("Medium - Pizza", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText4 = Text::Create("Hard - Pasta", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText5 = Text::Create("BACK", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);

	buttons.push_back(bodyText1);
	buttons.push_back(bodyText2);
	buttons.push_back(bodyText3);
	buttons.push_back(bodyText4);
	buttons.push_back(bodyText5);

	pointedButton = bodyText1;
}

LevelSelectScene::~LevelSelectScene()
{
	for (Text *text : buttons)
	{
		delete text;
	}

	delete topText;

	delete background;
}

void LevelSelectScene::ManeuverMenu()
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

void LevelSelectScene::CheckButtonClick()
{
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN))
	{
		auto bgMusicPlayer = AudioPlayer::GetPersistent(BG_AUDIO_TAG);

		Context::Get()->GetInputManager()->ClearAll();
		if (pointedButton == bodyText1) // Newbie - Fried Basket
		{
			Context::Get()->GetSceneManager()->LoadGameScene(&FOOD_MENU_FB);
			bgMusicPlayer->Stop();
		}
		else if (pointedButton == bodyText2) // Easy - Sashimi + Sushi
		{
			Context::Get()->GetSceneManager()->LoadGameScene(&FOOD_MENU_SS);
			bgMusicPlayer->Stop();
		}
		else if (pointedButton == bodyText3) // Medium - Pizza
		{
			Context::Get()->GetSceneManager()->LoadGameScene(&FOOD_MENU_PIZZA);
			bgMusicPlayer->Stop();
		}
		else if (pointedButton == bodyText4) // Hard - Pasta
		{
			Context::Get()->GetSceneManager()->LoadGameScene(&FOOD_MENU_PASTA);
			bgMusicPlayer->Stop();
		}
		else if (pointedButton == bodyText5) // BACK
		{
			Context::Get()->GetSceneManager()->LoadMainMenuScene();
		}
	}
}

void LevelSelectScene::Update(float deltaTime)
{
	background->Draw(Vector2(0, 0));

	ManeuverMenu();
	CheckButtonClick();

	int noOfLevels = buttons.size() - 1;
	int count = 0;
	topText->Draw(Vector2(0, 0));
	
	for (Text *button : buttons)
	{
		if (count == noOfLevels) // last button - BACK button
		{
			button->Draw(Vector2(0, GAME_HEIGHT - FONT_SIZE));
		}
		else
		{
			button->Draw(Vector2(0, (GAME_HEIGHT*0.5f - (noOfLevels/2 * FONT_SIZE)) + (FONT_SIZE * count)));
		}
		count++;
	}
}
