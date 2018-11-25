#pragma once

#include <winnt.h>
#include "animatedSprite.h"
#include "gameEntity.h"
#include "../game/player.h"

namespace core 
{
	class Game 
	{
	private:
		LARGE_INTEGER timeEnd;
		LARGE_INTEGER timeStart;
		LARGE_INTEGER timerFreq;

		float deltaTime = 0;

		const float MAX_FRAME_RATE = 60.0f;
		const float MIN_FRAME_RATE = 30.0f;
		const float MAX_FRAME_TIME = 1.0f / MIN_FRAME_RATE;
		const float MIN_FRAME_TIME = 1.0f / MAX_FRAME_RATE;
		
		Sprite *map = NULL;
		GameEntity *player = NULL;

	public:
		Game();
		~Game();

		void Initialize();
		void Run();

		float GetDeltaTime();
	};
}