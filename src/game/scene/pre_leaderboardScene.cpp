#include <iostream>
#include "pre_leaderboardScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

PreLeaderboardScene::PreLeaderboardScene()
	: Scene(SceneType::PRE_LEADERBOARD)
{
	background = Sprite::Create(BACKGROUND_IMAGE_OTHERS, 0);

	topText = Text::Create("Leaderboard Levels", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);

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

PreLeaderboardScene::~PreLeaderboardScene()
{
	for (Text *text : buttons)
	{
		delete text;
	}

	delete topText;

	delete background;
}

void PreLeaderboardScene::ManeuverMenu()
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

void PreLeaderboardScene::CheckButtonClick()
{
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN))
	{
		Context::Get()->GetInputManager()->ClearAll();
		if (pointedButton == bodyText1)
		{
			Context::Get()->GetSceneManager()->LoadLeaderboardScene(false, 0, "Fried Basket");
		}
		else if (pointedButton == bodyText2)
		{
			Context::Get()->GetSceneManager()->LoadLeaderboardScene(false, 0, "Sashimi & Sushi");
		}
		else if (pointedButton == bodyText3)
		{
			Context::Get()->GetSceneManager()->LoadLeaderboardScene(false, 0, "Pizza");
		}
		else if (pointedButton == bodyText4)
		{
			Context::Get()->GetSceneManager()->LoadLeaderboardScene(false, 0, "Pasta");
		}
		else if (pointedButton == bodyText5)
		{
			Context::Get()->GetSceneManager()->LoadMainMenuScene();
		}
	}
}

void PreLeaderboardScene::Update(float deltaTime)
{
	background->Draw(Vector2(0, 0));

	ManeuverMenu();
	CheckButtonClick();

	int count = 0;
	int noOfLevels = buttons.size() - 1;
	topText->Draw(Vector2(0, 0));

	for (Text *button : buttons)
	{
		if (count == noOfLevels) // last button - BACK button
		{
			button->Draw(Vector2(0, GAME_HEIGHT - FONT_SIZE));
		}
		else
		{
			button->Draw(Vector2(0, (GAME_HEIGHT*0.5f - (noOfLevels / 2 * FONT_SIZE)) + (FONT_SIZE * count)));
		}
		count++;
	}
}
