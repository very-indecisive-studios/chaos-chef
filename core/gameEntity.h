#pragma once

#include "math.h"

namespace core {
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
}