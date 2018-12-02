#include <iostream>
#include <string>
#include <map>
#include "leaderboardScene.h"
#include "game/resources.h"
#include "context.h"

LeaderboardScene::LeaderboardScene() : Scene(SceneType::LEADERBOARD){ }

LeaderboardScene::~LeaderboardScene()
{
	End();
}

void LeaderboardScene::AddPlayer()
{
	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN)) { enterPressed = true; }

	if (!enterPressed)
	{
		currentName = Context::Get()->GetInputManager()->GetTextIn();

		std::string addPlayerString = "Enter your name: " + currentName;

		bodyText->SetText(addPlayerString);
	}
	else
	{
		currentScore = 3110;
		// when there are 2 players with the same score
		if (leaderboard[currentScore] != "")
		{
			std::string newName = leaderboard[currentScore] + " & " + currentName;
			leaderboard[currentScore] = newName;
		}
		else
		{
			//leaderboard.insert(std::pair<int, std::string>(currentScore, currentName));
			leaderboard[currentScore] = currentName;
		}
		playerAdded = true;
	}
}

void LeaderboardScene::PrintLeaderboard()
{
	std::string leaderboardString = "Leaderboard \n \n";
	int position = 1;

	// Create a map reverse_iterator and point to end of map
	std::map<int, std::string>::reverse_iterator it = leaderboard.rbegin();

	// Iterate over the map using Iterator till the beginning of map
	while (it != leaderboard.rend())
	{
		// Accessing KEY from element pointed by it
		int score = it->first;

		// Accessing VALUE from element pointed by it
		std::string name = it->second;

		// Adding each line
		leaderboardString += "#" + std::to_string(position) + "     " + name + ": " + std::to_string(score) + " points\n";

		// Increment the Iterator to point to next entry
		it++;
		position++;
	}
	bodyText->SetText(leaderboardString);
}

void LeaderboardScene::Begin()
{
	topText = Text::Create("GAME OVER", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bodyText = Text::Create("", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	bottomText = Text::Create("Press enter to continue", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);

	leaderboard.insert(std::pair<int, std::string>(30, "Pam"));
	leaderboard.insert(std::pair<int, std::string>(1, "Los"));
	leaderboard.insert(std::pair<int, std::string>(100, "Jon"));
	leaderboard.insert(std::pair<int, std::string>(111, "Sam"));
}

void LeaderboardScene::Update(float deltaTime)
{
	topText->Draw(Vector2(0, 0));
	bottomText->Draw(Vector2(0, GAME_HEIGHT - FONT_SIZE));
	if (!playerAdded) 
	{
		AddPlayer();
	}
	else
	{
		if (delayEnter) 
		{
			Context::Get()->GetInputManager()->ClearAll();
			delayEnter = false;
		}
		PrintLeaderboard();
		if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN))
		{
			Context::Get()->GetSceneManager()->LoadGameScene();
		}
	}
	bodyText->Draw(Vector2(0, 100));
}

void LeaderboardScene::End() {}