#include "orderManager.h"
#include <ctime>

OrderManager::OrderManager(const FoodMenu* foodMenu, float nextOrderIntervalSeconds)
	: foodMenu(foodMenu), nextOrderIntervalSeconds(nextOrderIntervalSeconds)
{
	srand(time(nullptr));

	newOrderSoundPlayer = AudioPlayer::Create(NEW_ORDER_AUDIO);
}

OrderManager::~OrderManager()
{
	for (Order *order : orderQueue)
	{
		delete order;
	}

	orderQueue.clear();

	delete newOrderSoundPlayer;
}

void OrderManager::Update(float deltaTime)
{
	for (Order *order : currentOrder)
	{
		if (order != nullptr)
		{
			order->timeRemainingSeconds -= deltaTime;

			if (order->timeRemainingSeconds <= 0)
			{
				hasOrderMissed = true;
			}
		}
	}

	totalTime += deltaTime;
	timeElapsed += deltaTime;
	if(totalTime >= 30)
	{
		nextOrderIntervalSeconds -= 1;
		totalTime = 0;
	}
	//if (timeElapsed >= nextOrderIntervalSeconds-2)
	//{
		//customers[]
	//}
	if (timeElapsed >= nextOrderIntervalSeconds)
	{
		int pos = rand() % foodMenu->meals.size();
		const Meal *meal = foodMenu->meals.at(pos);
		Order *newOrder = new Order{ meal, 60 };

		orderQueue.push_back(newOrder);

		timeElapsed = 0;

		// Check for any available order hud to render an order.
		//for (OrderHud &oHud : orderHuds)
		//{
		//	if (oHud.GetOrder() == nullptr)
		//	{
		//		oHud.SetOrder(newOrder);
		//		break;
		//	}
		//}
	}

	for (int i = 0; i < 4; i++) 
	{
		if (currentOrder[i] == nullptr && orderQueue.size() > 0) 
		{
			Order *newOrder = orderQueue.back();
			orderQueue.pop_back();
			currentOrder[i] = newOrder;
			orderHuds[i].SetOrder(newOrder);
			newOrderSoundPlayer->Play();
		}
	}

	for (OrderHud &oHud : orderHuds)
	{
		oHud.Update(deltaTime);
	}
}

bool OrderManager::HasMissedOrder()
{
	return hasOrderMissed;
}

std::vector<Order *> OrderManager::GetOrders()
{
	return orderQueue;
}

std::vector<const PlatedFood *> OrderManager::GetCounterOrder(int counterNo)
{
	std::vector<const PlatedFood *> counterOrder;
	if (currentOrder[counterNo] != nullptr)
	{
		for (const PlatedFood *p : currentOrder[counterNo]->meal->foods)
		{
			counterOrder.push_back(p);
		}
	}
	return counterOrder;
}

void OrderManager::ClearCounterOrder(int counterNo)
{
	score += 100;
	currentOrder[counterNo] = nullptr;
	orderHuds[counterNo].ClearOrder();
}

int OrderManager::GetScore()
{
	return score;
}