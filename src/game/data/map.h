#pragma once
#include "game/entity/gameEntity.h"
#include "core/math.h"
#include <map>
#include <vector>
#include <utility>

namespace Map
{
	const uint8_t TILE_SIZE = 16;

	const std::map<Vector2, CollisionBounds> PROPS_LOCATION_BOUNDS = 
	{
		// Top wall.
		{ Vector2(0, 0)  * TILE_SIZE, CollisionBounds { Vector2(0, 0), (Vector2(8, 2) * TILE_SIZE) } },
		
		// Bottom wall.
		{ Vector2(0, 19) * TILE_SIZE, CollisionBounds { Vector2(0, 0), (Vector2(8, 1) * TILE_SIZE) } },
		
		// Counter.
		{ Vector2(34, 0) * TILE_SIZE, CollisionBounds { Vector2(0, 0), (Vector2(1, 20) * TILE_SIZE) } }
	};

	const std::map<Vector2, Vector2> DISPENSERS_W_AREA_LOCATIONS = 
	{
		{ { Vector2(0, 5) * TILE_SIZE }, { Vector2(2, 5) * TILE_SIZE } } ,
		{ { Vector2(0, 8) * TILE_SIZE }, { Vector2(2, 8) * TILE_SIZE } },
		{ { Vector2(0, 11) * TILE_SIZE }, { Vector2(2, 11) * TILE_SIZE } },
		{ { Vector2(0, 14) * TILE_SIZE }, { Vector2(2, 14) * TILE_SIZE } },
		{ { Vector2(0, 17) * TILE_SIZE }, { Vector2(2, 17) * TILE_SIZE } }
	};

	const std::vector<Vector2> COUNTER_AREA =
	{
		{ Vector2(32, 3) * TILE_SIZE },
		{ Vector2(32, 7) * TILE_SIZE },
		{ Vector2(32, 11) * TILE_SIZE },
		{ Vector2(32, 15) * TILE_SIZE }
	};

	const std::pair<Vector2, CollisionBounds> TRASH_BIN_LOCATION_BOUNDS = { Vector2(6, 3) * TILE_SIZE, CollisionBounds { Vector2(0, 0) * TILE_SIZE, Vector2(1, 1) * TILE_SIZE } };
	const std::pair<Vector2, CollisionBounds> TRASH_BIN_AREA_LOCATION_BOUNDS = { Vector2(5, 3) * TILE_SIZE, CollisionBounds { Vector2(0, 0) * TILE_SIZE, Vector2(2, 2) * TILE_SIZE } };
}
