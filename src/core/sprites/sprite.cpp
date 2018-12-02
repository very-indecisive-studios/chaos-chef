#include "core/sprites/sprite.h"
#include "core/graphics/graphicsRenderer.h"
#include "context.h"
#include <iostream>

Sprite::Sprite(Texture *texture, uint8_t layer, int scale)
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

void Sprite::Draw(Vector2 position)
{
	auto graphicsRenderer
			= Context::Get()->GetGraphicsRenderer();

	DrawSpriteJob *job = new DrawSpriteJob(this, position, layer);

	graphicsRenderer->QueueDrawJob(job);
}

Texture * Sprite::GetTexture()
{
	return this->texture;
}

int Sprite::GetHeight()
{
	return this->height;
}

int Sprite::GetWidth()
{
	return this->width;
}

int Sprite::GetScale()
{
	return this->scale;
}

DrawingArea * Sprite::GetDrawingArea()
{
	return &(this->drawingArea);
}

Sprite * Sprite::Create(const std::string& textureName, uint8_t layer, int scale)
{
	auto texture 
		= Context::Get()->GetResourceManager()->GetTexture(textureName);

	return new Sprite(texture, layer, scale);
}

uint8_t Sprite::GetLayer()
{
	return layer;
}