#pragma once
#include <iostream>
#include <string>
#include "game/entity/gameEntity.h"
#include "core/audio/audio.h"

class TrashBinArea : public GameEntity
{
private:
	int trashScore = 0;

	AudioPlayer *trashSoundPlayer;
public:
	TrashBinArea();
	~TrashBinArea();
	void PlayerClearedPlate();
	void Update(float deltaTime) override;
	int GetTrashScore();
};
