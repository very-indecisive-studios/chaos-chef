#pragma once

#include <vector>
#include "game/entity/gameEntity.h"

enum SceneType
{
	MAIN_MENU,
	PRE_LEADERBOARD,
	LEVEL_SELECT,
	GAME,
	LEADERBOARD
};

class Scene
{
private:
	SceneType type;

protected:
	Scene(SceneType type);

public:
	virtual ~Scene();
	SceneType GetType() { return type; }

	virtual void Update(float deltaTime) = 0;
};
