#pragma once

#include <vector>
#include "game/data/food.h"

struct Order
{
	const Meal *meal;
	float timeRemainingSeconds;
};

class OrderManager
{
private:
	std::vector<Order *> orderQueue;

	const FoodMenu *foodMenu;
	
	float nextOrderIntervalSeconds;
	float timeElapsed = 0;
	bool hasOrderMissed = false;
public:
	OrderManager(const FoodMenu *foodMenu, float nextOrderIntervalSeconds);
	~OrderManager();

	void Update(float deltaTime);
	bool HasMissedOrder();
	std::vector<Order *> GetOrders();
};
