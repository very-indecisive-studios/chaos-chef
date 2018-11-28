#include <iostream>
#include "trashBinArea.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

TrashBinArea::TrashBinArea() 
	: GameEntity(GameEntityType::TRASH_BIN_AREA)
{ }

TrashBinArea::~TrashBinArea() 
{ }

void TrashBinArea::Update(float deltaTime)
{ }