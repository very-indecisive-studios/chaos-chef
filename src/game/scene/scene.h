#pragma once

#include <vector>
#include "game/entity/gameEntity.h"

enum SceneType
{
	MAIN_MENU,
	GAME,
	PAUSED_MENU,
	LEVEL_SELECT,
	LEADERBOARD
};

class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Begin() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void End() = 0;
};
