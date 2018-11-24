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
private:
	SceneType type;

	std::vector<GameEntity *> entities;

	void AddGameEntity(GameEntity *entity);
public:
	Scene(SceneType type);
	virtual ~Scene();

	virtual void Initialize() = 0;
	virtual void Update(float deltaTime);

	SceneType GetType();
};
