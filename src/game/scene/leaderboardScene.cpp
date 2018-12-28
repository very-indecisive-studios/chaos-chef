#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include "leaderboardScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

LeaderboardScene::LeaderboardScene(bool needAddPlayer, int totalScore, std::string level)
	: Scene(SceneType::LEADERBOARD)
{
	background = Sprite::Create(BACKGROUND_IMAGE_OTHERS, 0);

	playerScore = totalScore;
	requireAdditionOfPlayer = needAddPlayer;
	currentLevel = level;
	if (currentLevel == "Fried Basket")
	{
		topText = Text::Create("GAME OVER\nNewbie - Fried Basket", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	}
	else if (currentLevel == "Sashimi & Sushi")
	{
		topText = Text::Create("GAME OVER\nEasy - Sashimi + Sushi", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	}
	else if (currentLevel == "Pizza")
	{
		topText = Text::Create("GAME OVER\nMedium - Pizza", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	}
	else if (currentLevel == "Pasta")
	{
		topText = Text::Create("GAME OVER\nHard - Pasta", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	}
	bodyText = Text::Create("", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bottomText = Text::Create("Press enter to continue", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
}

LeaderboardScene::~LeaderboardScene()
{
	delete topText;
	topText = nullptr;

	delete bodyText;
	bodyText = nullptr;

	delete bottomText;
	bottomText = nullptr;

	delete background;
	background = nullptr;
}

void LeaderboardScene::AddPlayer(int playerScore)
{
	topText->Draw(Vector2(0, 0));
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN)) 
	{
		enterPressed = true;
		Context::Get()->GetInputManager()->ClearAll();
	}

	if (!enterPressed)
	{
		currentName = Context::Get()->GetInputManager()->GetTextInWithLimit(NAME_INPUT_LIMIT, CHAR_LIMIT);

		std::string addPlayerString = "Enter your name: " + currentName;

		bodyText->SetText(addPlayerString);
	}
	else
	{
		std::ofstream leaderboardFile; // ofstream - write to file
		if (currentLevel == "Fried Basket")
		{
			leaderboardFile.open(LEADERBOARD_DATA_FRIED_BASKET, std::ios_base::app); // app - append
		}
		else if (currentLevel == "Sashimi & Sushi")
		{
			leaderboardFile.open(LEADERBOARD_DATA_S_AND_S, std::ios_base::app);
		}
		else if (currentLevel == "Pizza")
		{
			leaderboardFile.open(LEADERBOARD_DATA_PIZZA, std::ios_base::app);
		}
		else if (currentLevel == "Pasta")
		{
			leaderboardFile.open(LEADERBOARD_DATA_PASTA, std::ios_base::app);
		}
		leaderboardFile << currentName + "," + std::to_string(playerScore) + "\n";
		leaderboardFile.close();

		playerAdded = true;
		enterPressed = false;
	}
}

void LeaderboardScene::PrintLeaderboard()
{
	std::string leaderboardString;
	int position = 0;
	int previousPlayerScore = NULL;

	std::string currentLine;

	leaderboard.clear();

	std::ifstream leaderboardFile; // ifstream - read from file

	if (currentLevel == "Fried Basket")
	{
		leaderboardString = "Leaderboard - Fried Basket\n \n";
		leaderboardFile.open(LEADERBOARD_DATA_FRIED_BASKET); // app - append
	}
	else if (currentLevel == "Sashimi & Sushi")
	{
		leaderboardString = "Leaderboard - Sashimi + Sushi\n \n";
		leaderboardFile.open(LEADERBOARD_DATA_S_AND_S);
	}
	else if (currentLevel == "Pizza")
	{
		leaderboardString = "Leaderboard - Pizza\n \n";
		leaderboardFile.open(LEADERBOARD_DATA_PIZZA);
	}
	else if (currentLevel == "Pasta")
	{
		leaderboardString = "Leaderboard - Pasta\n \n";
		leaderboardFile.open(LEADERBOARD_DATA_PASTA);
	}

	while (std::getline(leaderboardFile, currentLine))
	{
		std::string currentName;
		std::string currentScore;
		bool reachedCHAR_LIMIT = false;

		for (char c : currentLine) 
		{
			if (c == CHAR_LIMIT)
			{
				reachedCHAR_LIMIT = true;
			}
			else
			{
				if (!reachedCHAR_LIMIT)
				{
					currentName += c;
				}
				else
				{
					currentScore += c;
				}
			}
		}
		leaderboard.push_back(PlayerScore(currentName, std::stoi(currentScore)));
	}

	std::sort(leaderboard.begin(), leaderboard.end(), std::greater<PlayerScore>());

	for (PlayerScore playerInLeaderboard : leaderboard)
	{
		if (playerInLeaderboard.score != previousPlayerScore) // if current player has same score as previous player, position do not change
		{
			position++;
		}

		previousPlayerScore = playerInLeaderboard.score; // keep track of player score to check if next player has the same score

		leaderboardString += "#" + std::to_string(position) + "     " + playerInLeaderboard.name + ": " + std::to_string(playerInLeaderboard.score) + " points\n";
	}

	bodyText->SetText(leaderboardString);
}

void LeaderboardScene::ProcessLeaderboard(int playerScore) 
{
	if (!playerAdded && requireAdditionOfPlayer)
	{
		AddPlayer(playerScore);
	}
	else
	{
		PrintLeaderboard();
		if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN))
		{
			Context::Get()->GetInputManager()->ClearAll();
			playerAdded = false;
			Context::Get()->GetSceneManager()->LoadMainMenuScene();
		}
	}
	bodyText->Draw(Vector2(0, FONT_SIZE * 2.5));
}

void LeaderboardScene::Update(float deltaTime)
{
	background->Draw(Vector2(0, 0));

	ProcessLeaderboard(playerScore);

	bottomText->Draw(Vector2(0, GAME_HEIGHT - FONT_SIZE));
}
