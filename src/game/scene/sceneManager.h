#pragma once
#include "scene.h"
#include "mainMenuScene.h"
#include "levelSelectScene.h"
#include "gameScene.h"
#include "leaderboardScene.h"
#include "pre_leaderboardScene.h"
#include "instructionScene.h"
#include "gameOverScene.h"

class SceneManager
{
private:
	Scene *currentScene = nullptr;
	Scene *pendingSceneToLoad = nullptr;

public:
	SceneManager();
	~SceneManager();

	void Initialize();

	void LoadMainMenuScene();
	void LoadInstructionScene();
	void LoadPreLeaderboardScene();
	void LoadSelectLevelScene();
	void LoadGameScene(const FoodMenu *foodMenu);
	void LoadGameOverScene(int reason, bool needAddPlayer, int playerScore, std::string level);
	void LoadLeaderboardScene(bool needAddPlayer, int playerScore, std::string level);

	void Update(float deltaTime);
};
