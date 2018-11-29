#pragma once
#include "scene.h"

class LevelSelectScene : public Scene
{
private:

public:
	LevelSelectScene();
	~LevelSelectScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
