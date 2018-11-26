#pragma once

#include "core/math.h"

struct CollisionBounds
{
	Vector2 topLeft;
	Vector2 bottomRight;
};
	
enum class GameEntityType 
{
	PLAYER,
	FOOD,
	DISPENSER,
	DISPENSER_AREA,
	TRASH_BIN,
	TRASH_BIN_AREA,
	COUNTER,
	COUNTER_AREA,
	CUSTOMER,
	VEHICLE
};

class GameEntity 
{
private:
	GameEntityType type;

protected:
	GameEntity(GameEntityType type);
	Vector2 position;
	CollisionBounds collisionBounds;

public:
	virtual ~GameEntity();
	GameEntityType GetType() { return type; }
	Vector2 GetPosition() { return position; }
	CollisionBounds GetCollisionBounds() { return collisionBounds; }
	void SetPosition(Vector2 inputPosition) { position = inputPosition; }
	void SetCollisionBounds(CollisionBounds inputCollisionBounds) { collisionBounds = inputCollisionBounds; }

	virtual void Update(float deltaTime) = 0;
	virtual bool CollidedWith(GameEntity *gameEntity);
};
