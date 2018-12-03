#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include "leaderboardScene.h"
#include "game/resources.h"
#include "context.h"
#include "constants.h"

LeaderboardScene::LeaderboardScene() : Scene(SceneType::LEADERBOARD){ }

LeaderboardScene::~LeaderboardScene()
{
	End();
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
		leaderboard.push_back(PlayerScore(currentName, 100)); //REMEMBER TO CHANGE - score needs to be added dynamically

		playerAdded = true;
		enterPressed = false;
	}
}

void LeaderboardScene::PrintLeaderboard()
{
	std::string leaderboardString = "Leaderboard \n \n";
	int position = 0;
	int previousPlayerScore = NULL;

	std::sort(leaderboard.begin(), leaderboard.end());

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
	if (!playerAdded)
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

void LeaderboardScene::Begin()
{
	topText = Text::Create("GAME OVER", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText = Text::Create("", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bottomText = Text::Create("Press enter to continue", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	leaderboard.push_back(PlayerScore("Sam",1));
	leaderboard.push_back(PlayerScore("Tim", 100));
	leaderboard.push_back(PlayerScore("Tom", 0));
}

void LeaderboardScene::Update(float deltaTime)
{
	topText->Draw(Vector2(0, 0));
	bottomText->Draw(Vector2(0, GAME_HEIGHT - FONT_SIZE));
	ProcessLeaderboard();
}

void LeaderboardScene::End() {}