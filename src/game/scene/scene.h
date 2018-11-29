#pragma once

#include <vector>
#include "game/entity/gameEntity.h"

enum SceneType
{
	MAIN_MENU,
	LEVEL_SELECT,
	GAME,
	PAUSED_MENU,
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
	virtual void Begin() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void End() = 0;
};
