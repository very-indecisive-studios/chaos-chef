#pragma once

#include <stdint.h>
#include "core/math.h"

struct CollisionBounds
{
	Vector2 topLeft;
	Vector2 bottomRight;
};
	
enum GameEntityType 
{
	PLAYER,
	FOOD,
	DISPENSER,
	TRASH_BIN,
	COUNTER,
	CUSTOMER,
	VEHICLE
};

enum GameEntityLayer : uint8_t
{
	BACKGROUND = 0,
	ENTITIES = 1
};

class GameEntity 
{
private:
	GameEntityType type;
protected:
	Vector2 position;
	CollisionBounds collisionBounds;
public:
	GameEntity(GameEntityType type);
	virtual ~GameEntity();
	virtual void Update(float deltaTime) = 0;
	virtual void Collided(GameEntity &gameEntity) = 0;
};
