#include "sprite.h"
#include "context.h"
#include <iostream>

core::Sprite::Sprite(Texture *texture, SpriteLayer layer, int scale)
{
	this->texture = texture;
	this->scale = scale;
	this->width = texture->GetWidth();
	this->height = texture->GetHeight();
	this->layer = layer;

	this->drawingArea = { 0 };
	this->drawingArea.right = this->width;
	this->drawingArea.bottom = this->height;
}

void core::Sprite::Draw(core::Vector2 position)
{
	auto graphicsRenderer
			= core::Context::Get()->GetGraphicsRenderer();

	core::DrawSpriteJob *job = new DrawSpriteJob();
	job->pos = position;
	job->sprite = this;

	graphicsRenderer->QueueSpriteDrawJob(job);
}

core::Texture * core::Sprite::GetTexture()
{
	return this->texture;
}

int core::Sprite::GetHeight()
{
	return this->height;
}

int core::Sprite::GetWidth()
{
	return this->width;
}

int core::Sprite::GetScale()
{
	return this->scale;
}

core::DrawingArea * core::Sprite::GetDrawingArea()
{
	return &(this->drawingArea);
}

core::Sprite * core::Sprite::Create(const std::string& textureName, SpriteLayer layer, int scale)
{
	auto texture 
		= core::Context::Get()->GetResourceManager()->GetTexture(textureName);

	return new core::Sprite(texture, layer, scale);
}

core::SpriteLayer core::Sprite::GetLayer() 
{
	return layer;
}