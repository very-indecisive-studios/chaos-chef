#pragma once
#include "scene.h"
#include "core/text/text.h"
#include "core/sprites/sprite.h"

class PreLeaderboardScene : public Scene
{
private:

public:
	PreLeaderboardScene();
	~PreLeaderboardScene();

	Sprite *background = nullptr;
	Text *topText;

	Text *bodyText1;
	Text *bodyText2;
	Text *bodyText3;
	Text *bodyText4;
	Text *bodyText5;

	Text *pointedButton;
	std::vector<Text *> buttons;

	int pointedButtonPos = 0;

	void ManeuverMenu();
	void CheckButtonClick();

	void Update(float deltaTime) override;
};
