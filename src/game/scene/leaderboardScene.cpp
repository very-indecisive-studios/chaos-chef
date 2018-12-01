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
		std::cout << currentName << std::endl;
	}
	else
	{
		currentScore = 30;
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

		std::cout << "#" << position << "   " << name << ": " << score << std::endl;

		// Increment the Iterator to point to next entry
		it++;
		position++;
	}
}

void LeaderboardScene::Begin() 
{
	leaderboard.insert(std::pair<int, std::string>(30, "Pam"));
	leaderboard.insert(std::pair<int, std::string>(1, "Loser"));
	leaderboard.insert(std::pair<int, std::string>(100, "John"));
	leaderboard.insert(std::pair<int, std::string>(111, "Sam"));
	Context::Get()->GetGraphicsRenderer()->SetBackColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	Context::Get()->GetGraphicsRenderer()->InitializeText(62, true, false, "Arial");
	Context::Get()->GetGraphicsRenderer()->SetFontColor(D3DCOLOR_ARGB(255, 255, 255, 255));
	Context::Get()->GetGraphicsRenderer()->Print("Melvin Ong", 0,0);
}

void LeaderboardScene::Update(float deltaTime)
{
	if (!playerAdded) 
	{
		AddPlayer();
	}
	else if (count == 0)
	{
		PrintLeaderboard();
		count += 1;
	}
}

void LeaderboardScene::End() {}