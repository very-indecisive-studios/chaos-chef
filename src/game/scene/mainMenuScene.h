#pragma once
#include "scene.h"
#include "core/text/text.h"

class MainMenuScene : public Scene
{
private:

public:
	MainMenuScene();
	~MainMenuScene();

	std::vector<Text *> buttons;

	Text *topText;
	Text *bodyText1;
	Text *bodyText2;
	Text *bodyText3;
	Text *bodyText4;
	Text *pointedButton;
	int pointedButtonPos = 0;

	void ManeuverMenu();
	void CheckButtonClick();
	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
