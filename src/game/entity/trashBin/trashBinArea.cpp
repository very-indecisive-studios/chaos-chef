#include <iostream>
#include "trashBinArea.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"
#include "game/resources.h"

TrashBinArea::TrashBinArea() 
	: GameEntity(GameEntityType::TRASH_BIN_AREA)
{
	trashSoundPlayer = AudioPlayer::Create(TRASH_AUDIO);
}

TrashBinArea::~TrashBinArea() 
{ }

void TrashBinArea::PlayerClearedPlate()
{
	trashSoundPlayer->Play();
	trashScore += 20;
}
void TrashBinArea::Update(float deltaTime)
{ }

int TrashBinArea::GetTrashScore() 
{
	return trashScore;
}