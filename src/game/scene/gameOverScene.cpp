#include <iostream>
#include "gameOverScene.h"
#include "context.h"
#include "constants.h"

GameOverScene::GameOverScene(int reason, bool addPlayer, int playerScore, std::string level)
	: Scene(SceneType::MAIN_MENU)
{
	reasonOfGameOver = reason;
	toAddPlayer = addPlayer;
	score = playerScore;
	levelName = level;

	topText = Text::Create("GAME OVER", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE * 2, 100, false, false);

	if (reasonOfGameOver == 1) 
	{
		bodyText = Text::Create("Order time ran out!", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	}

	if (reasonOfGameOver == 2)
	{
		bodyText = Text::Create("Try not to get hit next time!", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);
	}

	bottomText = Text::Create("Press <ENTER> to continue", FONT_TYPE, FONT_COLOR_WHITE, FONT_SIZE, 100, false, false);

	background = Sprite::Create(BACKGROUND_IMAGE_OTHERS, 0);

	ripMusicPlayer = AudioPlayer::Create(RIP_AUDIO);
	ripMusicPlayer->Play();
}

GameOverScene::~GameOverScene()
{
	delete bodyText;
	delete bottomText;
	delete background;
	delete ripMusicPlayer;
}

void GameOverScene::Update(float deltaTime)
{
	background->Draw(Vector2(0, 0));

	topText->Draw(Vector2(0, 0));
	bodyText->Draw(Vector2(0, GAME_HEIGHT/2 - FONT_SIZE/2));
	bottomText->Draw(Vector2(0, GAME_HEIGHT - FONT_SIZE));

	if (Context::Get()->GetInputManager()->IsKeyDown(VK_RETURN))
	{
		Context::Get()->GetInputManager()->ClearAll();
		Context::Get()->GetSceneManager()->LoadLeaderboardScene(toAddPlayer, score, levelName);
	}
}