#pragma once
#include "scene.h"

class PausedMenuScene : public Scene
{
private:

public:
	PausedMenuScene();
	~PausedMenuScene();

	void Update(float deltaTime) override;
};
