#pragma once

#include "scene.h"

class GameScene : public Scene
{
private:
	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
	void CheckCollisions();
};