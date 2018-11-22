#include "scene.h"

core::Scene::Scene(SceneType type)
	:type(type)
{ }

core::Scene::~Scene()
{
	for (auto entity : entities) 
	{
		delete entity;
	}
}

void core::Scene::Update(float deltaTime)
{
	for (auto entity : entities)
	{
		entity->Update(deltaTime);
	}
}

void core::Scene::AddGameEntity(GameEntity *entity)
{
	entities.push_back(entity);
}

core::SceneType core::Scene::GetType() 
{
	return this->type;
}