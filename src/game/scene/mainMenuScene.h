#pragma once
#include "scene.h"
#include "core/text/text.h"

class MainMenuScene : public Scene
{
private:

public:
	MainMenuScene();
	~MainMenuScene();

	Text *topText;
	
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
