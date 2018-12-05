#pragma once

#include <vector>
#include "game/data/food.h"
#include "order.h"
#include "game/hud/order/orderHud.h"
#include "game/data/gameSceneData.h"
#include "game/entity/customer/customer.h" 

class OrderManager
{
private:
	std::vector<Order *> orderQueue;
	std::vector<Customer *> customers;
	const FoodMenu *foodMenu;
	
	float nextOrderIntervalSeconds;
	float timeElapsed = 0;
	float totalTime = 0;
	bool hasOrderMissed = false;
	int score = 0;

	OrderHud orderHuds[4] = {
		{ GameSceneData::Hud::Bottom::ORDER_HUD_LOCATION_1 },
		{ GameSceneData::Hud::Bottom::ORDER_HUD_LOCATION_2 },
		{ GameSceneData::Hud::Bottom::ORDER_HUD_LOCATION_3 },
		{ GameSceneData::Hud::Bottom::ORDER_HUD_LOCATION_4 }
	};

	Order *currentOrder[4]{ nullptr };
public:
	OrderManager(const FoodMenu *foodMenu, float nextOrderIntervalSeconds);
	~OrderManager();

	void Update(float deltaTime);
	bool HasMissedOrder();
	std::vector<Order *> GetOrders();
	std::vector<const PlatedFood *> GetCounterOrder(int counterNo);
	void ClearCounterOrder(int counterNo);
	int GetScore();
};
