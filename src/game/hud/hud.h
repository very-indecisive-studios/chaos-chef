#pragma once

#include "core/math.h"

class Hud
{
protected:
	Vector2 position;
public:
	Hud(Vector2 position);
	virtual ~Hud();

	virtual void Update(float deltaTime) = 0;
};