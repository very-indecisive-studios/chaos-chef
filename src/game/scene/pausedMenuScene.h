#pragma once
#include "scene.h"

class PausedMenuScene : public Scene
{
private:

public:
	PausedMenuScene();
	~PausedMenuScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
