#pragma once

#include "scene.h"
#include "core/sprites/sprite.h"
#include "core/text/text.h"

class GameOverScene : public Scene
{
private:
	int reasonOfGameOver;
	bool toAddPlayer;
	int score;
	std::string levelName;
	Sprite *background = nullptr;
	Text *topText = nullptr;
	Text *bodyText = nullptr;
	Text *bottomText = nullptr;

public:
	GameOverScene(int reason, bool addPlayer, int playerScore, std::string level);
	~GameOverScene();

	void Update(float deltaTime) override;
};
