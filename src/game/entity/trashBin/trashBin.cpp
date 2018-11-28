#include <iostream>
#include "trashBin.h"
#include "game/entity/gameEntity.h"
#include "core/math.h"

TrashBin::TrashBin() 
	: GameEntity(GameEntityType::TRASH_BIN) 
{ }

TrashBin::~TrashBin() 
{ }

void TrashBin::Update(float deltaTime)
{ }