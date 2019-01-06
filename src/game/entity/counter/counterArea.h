#pragma once

#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "game/gameplay/order/orderManager.h"

class CounterArea : public GameEntity
{
private:
	int counterNo;
	OrderManager *orderManager;

	AudioPlayer *orderSuccessSoundPlayer;
	AudioPlayer *wrongOrderSoundPlayer;
public:
	CounterArea(int counterNo, OrderManager *orderManager);
	~CounterArea();

	bool OrderSubmit(std::vector<const PlatedFood *> foodOnHand);
	void Update(float deltaTime) override;
};