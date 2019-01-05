#include <iostream>
#include "counterArea.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

CounterArea::CounterArea(int counterNo, OrderManager *orderManager) 
	: GameEntity(GameEntityType::COUNTER_AREA)
{
	this->counterNo = counterNo;
	this->orderManager = orderManager;
	collisionBounds.topLeft = Vector2(0, 0);
	collisionBounds.bottomRight = Vector2(10, 10);

	orderSuccessSoundPlayer = AudioPlayer::Create(DONE_ORDER_AUDIO);
}

CounterArea::~CounterArea()
{ }

bool CounterArea::OrderSubmit(std::vector<const PlatedFood *> foodOnHand)
{
	if (orderManager->GetCounterOrder(counterNo).size() == 0) { return false; }
	int orderIngreInHandIngre = 0;
	for (const PlatedFood *ingreOnCounter : orderManager->GetCounterOrder(counterNo))
	{
		for (const PlatedFood *ingreOnHand : foodOnHand) 
		{
			if (ingreOnHand == ingreOnCounter) 
			{
				orderIngreInHandIngre++;
			}
		}

	}

	if (orderIngreInHandIngre == orderManager->GetCounterOrder(counterNo).size() && orderManager->GetCounterOrder(counterNo).size() == foodOnHand.size()) //success
	{
		orderManager->ClearCounterOrder(counterNo);

		orderSuccessSoundPlayer->Play();

		return true;
	}
	else 
	{
		return false;
	}
}

void CounterArea::Update(float deltaTime)
{ }
