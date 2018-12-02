#pragma once

#include "scene.h"
#include <map>
#include <string>
#include "core/text/text.h"

class LeaderboardScene : public Scene
{
private:

public:
	LeaderboardScene();
	~LeaderboardScene();
	std::map<int, std::string> leaderboard;
	std::string currentName;
	int count = 0;
	int currentScore;
	bool enterPressed = false;
	bool playerAdded = false;
	Text *text;

	void AddPlayer();
	void PrintLeaderboard();
	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
