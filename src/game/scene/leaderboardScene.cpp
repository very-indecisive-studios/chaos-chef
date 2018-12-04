#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <fstream>
#include "leaderboardScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

LeaderboardScene::LeaderboardScene(bool needAddPlayer)
	: Scene(SceneType::LEADERBOARD)
{
	requireAdditionOfPlayer = needAddPlayer;
	topText = Text::Create("GAME OVER", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
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
}

void LeaderboardScene::AddPlayer()
{
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN)) 
	{
		enterPressed = true;
		Context::Get()->GetInputManager()->ClearAll();
	}

	if (!enterPressed)
	{
		currentName = Context::Get()->GetInputManager()->GetTextInWithLimit(NAME_INPUT_LIMIT);

		std::string addPlayerString = "Enter your name: " + currentName;

		bodyText->SetText(addPlayerString);
	}
	else
	{
		std::ofstream leaderboardFile; // ofstream - write to file
		leaderboardFile.open(LEADERBOARD_DATA,std::ios_base::app); // app - append
		leaderboardFile << currentName + "100\n"; //TO DO- score needs to be added dynamically
		leaderboardFile.close();

		playerAdded = true;
		enterPressed = false;
	}
}

void LeaderboardScene::PrintLeaderboard()
{
	std::string leaderboardString = "Leaderboard \n \n";
	int position = 0;
	int previousPlayerScore = NULL;

	std::string currentLine;

	leaderboard.clear();

	std::ifstream leaderboardFile; // ifstream - read from file
	leaderboardFile.open(LEADERBOARD_DATA);
	while (std::getline(leaderboardFile, currentLine))
	{
		std::string currentName;
		std::string currentScore;
		int count = 0;
		for (char c : currentLine) 
		{
			if (count < NAME_INPUT_LIMIT)
			{
				currentName += c;
			}
			else 
			{
				currentScore += c;
			}
			count++;
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

void LeaderboardScene::ProcessLeaderboard() 
{
	if (!playerAdded && requireAdditionOfPlayer)
	{
		AddPlayer();
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
	bodyText->Draw(Vector2(0, 100));
}

void LeaderboardScene::Update(float deltaTime)
{
	ProcessLeaderboard();

	topText->Draw(Vector2(0, 0));
	bottomText->Draw(Vector2(0, GAME_HEIGHT - FONT_SIZE));
}
