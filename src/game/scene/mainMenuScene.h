#pragma once

#include "scene.h"

class MainMenuScene : public Scene
{
private:

public:
	MainMenuScene();
	~MainMenuScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
