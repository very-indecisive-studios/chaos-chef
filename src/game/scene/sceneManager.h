#pragma once
#include "scene.h"
#include "mainMenuScene.h"
#include "levelSelectScene.h"
#include "pausedMenuScene.h"
#include "gameScene.h"
#include "leaderboardScene.h"

class SceneManager
{
private:
	MainMenuScene *mainMenuScene;
	LevelSelectScene *levelSelectScene;
	GameScene *gameScene;
	LeaderboardScene *leaderboardScene;
	Scene *currentScene;

public:
	SceneManager();
	~SceneManager();

	void LoadMainMenuScene();
	void LoadSelectLevelScene();
	void LoadGameScene();
	void LoadPausedMenuScene();
	void LoadLeaderboardScene();

	void Update(float deltaTime);
};
