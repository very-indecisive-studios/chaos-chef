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
	Text *pointedButton;
	bool delayPress = false;
	int pointedButtonPos = 0;

	void ManeuverMenu();
	void CheckButtonClick();
	void Begin() override;
	void Update(float deltaTime) override;
	void End() override;
};
