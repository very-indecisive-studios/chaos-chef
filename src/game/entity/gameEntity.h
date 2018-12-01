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
	COUNTER_AREA,
	CUSTOMER,
	VEHICLE,
	PROP
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
	GameEntityType GetType();
	Vector2 GetPosition();
	CollisionBounds GetCollisionBounds();
	void SetPosition(Vector2 position);
	void SetCollisionBounds(CollisionBounds collisionBounds);

	virtual void Update(float deltaTime);

	virtual bool CollidedWith(GameEntity *gameEntity);
	virtual void HandleCollision(GameEntity *gameEntity);
};
