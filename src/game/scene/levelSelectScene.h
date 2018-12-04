#pragma once
#include "scene.h"
#include "core/text/text.h"

class LevelSelectScene : public Scene
{
private:
	std::vector<Text *> buttons;

	Text *topText;

	Text *bodyText1;
	Text *bodyText2;
	Text *bodyText3;
	Text *bodyText4;
	Text *bodyText5;

	Text *pointedButton;

	int pointedButtonPos = 0;

public:
	LevelSelectScene();
	~LevelSelectScene();

	void ManeuverMenu();
	void CheckButtonClick();

	void Update(float deltaTime) override;
};
