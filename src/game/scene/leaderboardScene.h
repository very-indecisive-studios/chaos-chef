#pragma once

#include "scene.h"
#include <map>
#include <string>
#include "core/text/text.h"

struct PlayerScore
{
	std::string name;
	int score;

	PlayerScore(const std::string& n, int s) : score(s), name(n) {}

	bool operator < (const PlayerScore& str) const
	{
		return (score > str.score);
	}
};

class LeaderboardScene : public Scene
{
private:

public:
	LeaderboardScene();
	~LeaderboardScene();
	std::vector<PlayerScore> leaderboard;
	std::string currentName;
	int noOfChar = 0;
	bool enterPressed = false;
	bool playerAdded = false;
	Text *topText;
	Text *bodyText;
	Text *bottomText;

	void AddPlayer();
	void PrintLeaderboard();
	void ProcessLeaderboard();
	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
