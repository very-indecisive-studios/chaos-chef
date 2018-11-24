#include "scene.h"

Scene::Scene(SceneType type)
	:type(type)
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

SceneType Scene::GetType()
{
	return this->type;
}