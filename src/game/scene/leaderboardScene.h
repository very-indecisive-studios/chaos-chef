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
	int playerScore;
	std::vector<PlayerScore> leaderboard;
	std::string currentName;
	bool requireAdditionOfPlayer;
	int noOfChar = 0;
	bool enterPressed = false;
	bool playerAdded = false;
	Text *topText;
	Text *bodyText;
	Text *bottomText;
	int playerScore;

public:
	LeaderboardScene(bool needAddPlayer, int totalScore);
	~LeaderboardScene();

	void AddPlayer(int playerScore);
	void PrintLeaderboard();
	void ProcessLeaderboard(int playerScore);

	void Update(float deltaTime) override;
};
