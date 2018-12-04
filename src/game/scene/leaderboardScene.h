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

	bool operator > (const PlayerScore& str) const // overriding operator >
	{
		return (score > str.score);
	}
};

class LeaderboardScene : public Scene
{
private:
	std::vector<PlayerScore> leaderboard;
	std::string currentName;
	bool requireAdditionOfPlayer;
	int noOfChar = 0;
	bool enterPressed = false;
	bool playerAdded = false;
	Text *topText;
	Text *bodyText;
	Text *bottomText;

public:
	LeaderboardScene(bool needAddPlayer);
	~LeaderboardScene();

	void AddPlayer();
	void PrintLeaderboard();
	void ProcessLeaderboard();

	void Update(float deltaTime) override;
};
