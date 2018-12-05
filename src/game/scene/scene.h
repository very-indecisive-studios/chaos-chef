#pragma once

#include <vector>
#include "game/entity/gameEntity.h"

enum SceneType
{
	MAIN_MENU,
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
