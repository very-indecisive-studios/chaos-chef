#include <windows.h>
#include <Mmsystem.h>
#include "game.h"
#include "context.h"

core::Game::Game()
{
}

core::Game::~Game()
{
	delete animSprite;
	delete player;
}

void core::Game::Initialize()
{
	QueryPerformanceFrequency(&timerFreq);
	QueryPerformanceCounter(&timeStart);
	player = new game::Player();
	map->Create(MAP_IMAGE);
}

void core::Game::Run()
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
	player->Update(deltaTime);

	/*
		Render game.
	*/
	auto gR = core::Context::Get()->GetGraphicsRenderer();
	gR->Render();
	gR->HandleLostDevice();

	/*
		Reset input.
	*/
	auto iM = core::Context::Get()->GetInputManager();
	iM->ClearAll();
}

float core::Game::GetDeltaTime()
{
	return deltaTime;
}
