#include "scene.h"

Scene::Scene()
{ }

Scene::~Scene()
{
	for (auto entity : entities) 
	{
		delete entity;
	}
}

void Scene::Update(float deltaTime)
{
	for (auto entity : entities)
	{
		entity->Update(deltaTime);
	}
}

void Scene::AddGameEntity(GameEntity *entity)
{
	entities.push_back(entity);
}
