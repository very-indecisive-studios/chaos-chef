#pragma once

#include "scene.h"

class LeaderboardScene : public Scene
{
private:

public:
	LeaderboardScene();
	~LeaderboardScene();

	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
