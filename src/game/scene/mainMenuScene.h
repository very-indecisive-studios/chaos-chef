#pragma once
#include "scene.h"
#include "core/text/text.h"
#include "core/sprites/sprite.h"

class MainMenuScene : public Scene
{
private:

public:
	MainMenuScene();
	~MainMenuScene();

	Sprite *background = nullptr;
	
	Text *bodyText1;
	Text *bodyText2;
	Text *bodyText3;
	Text *pointedButton;
	std::vector<Text *> buttons;
	
	int pointedButtonPos = 0;

	void ManeuverMenu();
	void CheckButtonClick();

	void Update(float deltaTime) override;
};
