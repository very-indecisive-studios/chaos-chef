#pragma once

#include "scene.h"
#include "core/sprites/sprite.h"
#include "core/text/text.h"

class InstructionScene : public Scene
{
private:
	Sprite *instructions = nullptr;

public:
	InstructionScene();
	~InstructionScene();

	void Update(float deltaTime) override;
};
