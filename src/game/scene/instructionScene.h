#pragma once

#include "scene.h"
#include "core/sprites/sprite.h"
#include "core/text/text.h"

class InstructionScene : public Scene
{
private:
	int currentNo = 1;

	Sprite *instructions_1 = nullptr;
	Sprite *instructions_2 = nullptr;
	Sprite *instructions_3 = nullptr;
	Sprite *instructions_4 = nullptr;
	Sprite *instructions_5 = nullptr;
	Sprite *instructions_6 = nullptr;

	Text *text = nullptr;
	Text *smaller_text = nullptr;

	std::vector<Sprite *> list_of_instructions;
	
public:
	InstructionScene();
	~InstructionScene();

	void Update(float deltaTime) override;
};
