#include <windows.h>
#include <Mmsystem.h>
#include <iostream>
#include <string>
#include "game.h"
#include "core/sprites/sprite.h"
#include "context.h"
#include "game/resources.h"

Game::Game()
{
}

Game::~Game()
{
	delete player;
	delete map;
}

void Game::Initialize()
{
	QueryPerformanceFrequency(&timerFreq);
	QueryPerformanceCounter(&timeStart);

	player = new Player();
	map = Sprite::Create(MAP_IMAGE, 0);

	// Leaderboard prototype
	// References: https://thispointer.com/how-to-iterate-over-a-map-in-c/ & https://www.moderncplusplus.com/map/ & https://thispointer.com/how-to-iterate-a-map-in-reverse-order-c/
	std::map<int, std::string> leaderboard;
	leaderboard.insert(std::pair<int, std::string>(10000000, "Pam"));
	leaderboard.insert(std::pair<int, std::string>(1, "Loser"));
	leaderboard.insert(std::pair<int, std::string>(100, "John & Sam"));
	leaderboard.insert(std::pair<int, std::string>(111, "Mel"));

	std::string currentName = "van";
	int currentScore = 100;

	// when there are 2 players with the same score
	if (leaderboard[currentScore] != "")
	{
		std::string newName = leaderboard[currentScore] + " & " + currentName;
		leaderboard[currentScore] = newName;
	}
	else 
	{
		leaderboard.insert(std::pair<int, std::string>(currentScore, currentName));
	}

	// Create a map reverse_iterator and point to end of map
	std::map<int, std::string>::reverse_iterator it = leaderboard.rbegin();

	// Iterate over the map using Iterator till the beginning of map
	while (it != leaderboard.rend())
	{
		// Accessing KEY from element pointed by it
		int score = it->first;

		// Accessing VALUE from element pointed by it
		std::string name = it->second;

		std::cout << name << ": " << score << std::endl;

		// Increment the Iterator to point to next entry
		it++;
	}
}

void Game::Run()
{
	/*
		Calculate delta time + limit frame rate.
	*/

	// Calculate elapsed time of last frame, save in frameTime.
	QueryPerformanceCounter(&timeEnd);
	deltaTime = (float) (timeEnd.QuadPart - timeStart.QuadPart) / (float) timerFreq.QuadPart;

	// Power saving code; if not enough time has elapsed for desired frame rate.
	if (deltaTime < MIN_FRAME_TIME)
	{
		float sleepTime = (float) ((MIN_FRAME_TIME - deltaTime) * 1000);
		timeBeginPeriod(1);         // Request 1mS resolution for windows timer
		Sleep(sleepTime);           // release cpu for sleepTime
		timeEndPeriod(1);           // End 1mS timer resolution
		return;
	}

	// If frame rate is very slow.
	if (deltaTime > MAX_FRAME_TIME)
	{
		// Limit maximum frameTime.
		deltaTime = MAX_FRAME_TIME;
	}

	timeStart = timeEnd;

	/*
		Update game entities.
	*/
	map->Draw(Vector2(0, 0));
	player->Update(deltaTime);

	/*
		Render game.
	*/
	auto gR = Context::Get()->GetGraphicsRenderer();
	gR->Render();
	gR->HandleLostDevice();

	/*
		Reset input.
	*/
	auto iM = Context::Get()->GetInputManager();
	iM->ClearAll();
}

float Game::GetDeltaTime()
{
	return deltaTime;
}
