#pragma once
#include "game/entity/gameEntity.h"
#include "core/math.h"
#include <map>
#include <vector>
#include <utility>

// Contains coordinates of where huds, entities, props and other misc. stuff.
// Define (row, col) then multiplied by tile size for easy reference to actual mapping software.

namespace GameSceneData
{
	const uint8_t TILE_SIZE = 16;

	namespace Hud
	{
		namespace Top
		{
			static const Vector2 LOCATION = Vector2(0, 0) * TILE_SIZE;

			static const Vector2	HAND_TEXT_LOCATION				= Vector2(0.5, 0) * TILE_SIZE;

			static const Vector2	HAND_COMB_HUD_LOCATION			= Vector2(0, 1) * TILE_SIZE;
			
			static const Vector2	HAND_COMB_HUD_PF_REL_LOCATION	= Vector2(1, 0.5) * TILE_SIZE;
			static const int		HAND_COMB_HUD_PF_SCALE			= 2;

			static const Vector2	HAND_INDV_HUD_NEXT				= Vector2(4, 0) * TILE_SIZE;
			static const Vector2	HAND_INDV_HUD_LOCATION_1		= Vector2(10, 1) * TILE_SIZE;
			static const Vector2	HAND_INDV_HUD_LOCATION_2		= HAND_INDV_HUD_LOCATION_1 + HAND_INDV_HUD_NEXT;
			static const Vector2	HAND_INDV_HUD_LOCATION_3		= HAND_INDV_HUD_LOCATION_2 + HAND_INDV_HUD_NEXT;
			static const Vector2	HAND_INDV_HUD_LOCATION_4		= HAND_INDV_HUD_LOCATION_3 + HAND_INDV_HUD_NEXT;
			static const Vector2	HAND_INDV_HUD_LOCATION_5		= HAND_INDV_HUD_LOCATION_4 + HAND_INDV_HUD_NEXT;
			
			static const Vector2	HAND_INDV_HUD_ING_REL_LOCATION	= Vector2(0, 0.5) * TILE_SIZE;
			static const int		HAND_INDV_HUD_ING_SCALE			= 2;
		}

		namespace Bottom
		{
			static const Vector2 LOCATION = Vector2(0, 24) * TILE_SIZE;
			static const Vector2 ORDER_TEXT_LOCATION = Vector2(0.6, 24) * TILE_SIZE;

			static const Vector2	ORDER_HUD_NEXT			= Vector2(10, 0) * TILE_SIZE;
			static const Vector2	ORDER_HUD_LOCATION_1	= Vector2(0, 24) * TILE_SIZE;
			static const Vector2	ORDER_HUD_LOCATION_2	= ORDER_HUD_LOCATION_1 + ORDER_HUD_NEXT;
			static const Vector2	ORDER_HUD_LOCATION_3	= ORDER_HUD_LOCATION_2 + ORDER_HUD_NEXT;
			static const Vector2	ORDER_HUD_LOCATION_4	= ORDER_HUD_LOCATION_3 + ORDER_HUD_NEXT;

			static const int		ORDER_HUD_PF_SCALE			= 2;
			static const Vector2	ORDER_HUD_PF_REL_LOCATION	= Vector2(0.5, 1) * TILE_SIZE;

			static const int	ORDER_HUD_TEXT_SIZE = 16;

			static const Vector2	ORDER_HUD_TIME_REL_LOCATION = Vector2(5.5, 1) * TILE_SIZE;

			static const int	ORDER_HUD_IG_SCALE = 1;
			static const Vector2	ORDER_HUD_ING_REL_NEXT			= Vector2(2, 0) * TILE_SIZE;
			static const Vector2	ORDER_HUD_ING_REL_LOCATION_1	= Vector2(0, 4.5) * TILE_SIZE;
			static const Vector2	ORDER_HUD_ING_REL_LOCATION_2	= ORDER_HUD_ING_REL_LOCATION_1 + ORDER_HUD_ING_REL_NEXT;
			static const Vector2	ORDER_HUD_ING_REL_LOCATION_3	= ORDER_HUD_ING_REL_LOCATION_2 + ORDER_HUD_ING_REL_NEXT;
			static const Vector2	ORDER_HUD_ING_REL_LOCATION_4	= ORDER_HUD_ING_REL_LOCATION_3 + ORDER_HUD_ING_REL_NEXT;
			static const Vector2	ORDER_HUD_ING_REL_LOCATION_5	= ORDER_HUD_ING_REL_LOCATION_4 + ORDER_HUD_ING_REL_NEXT;
			static const std::vector<Vector2> ORDER_HUD_ING_REL_LOCATIONS =
			{
				ORDER_HUD_ING_REL_LOCATION_1,
				ORDER_HUD_ING_REL_LOCATION_2,
				ORDER_HUD_ING_REL_LOCATION_3,
				ORDER_HUD_ING_REL_LOCATION_4,
				ORDER_HUD_ING_REL_LOCATION_5
			};
		}
	}

	namespace Map
	{
		static const Vector2 LOCATION = Vector2(0, 4) * TILE_SIZE;
		static const int HEIGHT	= 320;
		static const int WIDTH		= 640;
		static const CollisionBounds BOUNDS = { LOCATION, LOCATION + Vector2(WIDTH, HEIGHT) };

		static const Vector2 VEHICLE_SPAWN_LOCATION1 = Vector2(11, 21) * TILE_SIZE;
		static const Vector2 VEHICLE_SPAWN_LOCATION2 = Vector2(17, 4) * TILE_SIZE;
		static const Vector2 VEHICLE_SPAWN_LOCATION3 = Vector2(23, 21) * TILE_SIZE;
		static const Vector2 VEHICLE_SPAWN_LOCATION4 = Vector2(29, 4) * TILE_SIZE;

		static const Vector2 PLAYER_SPAWN_LOCATION = Vector2(7, 14) * TILE_SIZE;

		const Vector2 CUSTOMER_SPAWN_LOCATION1 = Vector2(40, 4) * TILE_SIZE;
		const Vector2 CUSTOMER_SPAWN_LOCATION2 = Vector2(40, 4) * TILE_SIZE;
		const Vector2 CUSTOMER_SPAWN_LOCATION3 = Vector2(40, 4) * TILE_SIZE;
		const Vector2 CUSTOMER_SPAWN_LOCATION4 = Vector2(40, 4) * TILE_SIZE;

		const std::map<Vector2, CollisionBounds> PROPS_LOCATION_BOUNDS =
		{
			// Top wall.
			{ Vector2(0, 4)  * TILE_SIZE, CollisionBounds { Vector2(0, 0), (Vector2(8, 2) * TILE_SIZE) } },

			// Bottom wall.
			{ Vector2(0, 23) * TILE_SIZE, CollisionBounds { Vector2(0, 0), (Vector2(8, 1) * TILE_SIZE) } },

			// Counter.
			{ Vector2(34, 4) * TILE_SIZE, CollisionBounds { Vector2(0, 0), (Vector2(1, 20) * TILE_SIZE) } }
		};

		static const std::map<Vector2, Vector2> DISPENSERS_W_AREA_LOCATIONS =
		{
			{ { Vector2(0, 9) * TILE_SIZE }, { Vector2(2, 9) * TILE_SIZE } } ,
			{ { Vector2(0, 12) * TILE_SIZE }, { Vector2(2, 12) * TILE_SIZE } },
			{ { Vector2(0, 15) * TILE_SIZE }, { Vector2(2, 15) * TILE_SIZE } },
			{ { Vector2(0, 18) * TILE_SIZE }, { Vector2(2, 18) * TILE_SIZE } },
			{ { Vector2(0, 21) * TILE_SIZE }, { Vector2(2, 21) * TILE_SIZE } }
		};

		static const std::vector<Vector2> COUNTER_AREA =
		{
			{ Vector2(32, 8) * TILE_SIZE },
			{ Vector2(32, 12) * TILE_SIZE },
			{ Vector2(32, 16) * TILE_SIZE },
			{ Vector2(32, 20) * TILE_SIZE }
		};

		static const std::pair<Vector2, CollisionBounds> TRASH_BIN_LOCATION_BOUNDS = { Vector2(6, 7) * TILE_SIZE, CollisionBounds { Vector2(0, 0) * TILE_SIZE, Vector2(1, 1) * TILE_SIZE } };
		static const std::pair<Vector2, CollisionBounds> TRASH_BIN_AREA_LOCATION_BOUNDS = { Vector2(5, 7) * TILE_SIZE, CollisionBounds { Vector2(0, 0) * TILE_SIZE, Vector2(2, 2) * TILE_SIZE } };
	}
}


