#pragma once

#include <vector>
#include "game/data/food.h"
#include "order.h"
#include "game/hud/order/orderHud.h"

class OrderManager
{
private:
	std::vector<Order *> orderQueue;

	const FoodMenu *foodMenu;
	
	float nextOrderIntervalSeconds;
	float timeElapsed = 0;
	bool hasOrderMissed = false;

	OrderHud *orderHuds[4] = {
		new OrderHud(Vector2(0, MAP_HEIGHT + HAND_COMB_HUD_HEIGHT)),
		new OrderHud(Vector2(ORDER_HUD_WIDTH, MAP_HEIGHT + HAND_COMB_HUD_HEIGHT)),
		new OrderHud(Vector2(ORDER_HUD_WIDTH * 2, MAP_HEIGHT + HAND_COMB_HUD_HEIGHT)),
		new OrderHud(Vector2(ORDER_HUD_WIDTH * 3, MAP_HEIGHT + HAND_COMB_HUD_HEIGHT))
	};
public:
	OrderManager(const FoodMenu *foodMenu, float nextOrderIntervalSeconds);
	~OrderManager();

	void Update(float deltaTime);
	bool HasMissedOrder();
	std::vector<Order *> GetOrders();
};
