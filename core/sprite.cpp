#include "sprite.h"
#include "context.h"

core::Sprite::Sprite(Texture *texture, int scale)
{
	this->texture = texture;
	this->scale = scale;
	this->width = texture->GetWidth() * scale;
	this->height = texture->GetHeight() * scale;

	this->drawingArea = new core::DrawingArea { 0 };
	this->drawingArea->right = this->width;
	this->drawingArea->bottom = this->height;
}

core::Sprite::~Sprite()
{
	delete this->drawingArea;
	// Don't delete texture here. Other sprites may have reference to the texture.
	// Leave the deletion of texture to resource manager.
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
	return this->drawingArea;
}

core::Sprite * core::Sprite::Create(const std::string& textureName, int scale) {
	auto texture 
		= core::Context::Get()->GetResourceManager()->GetTexture(textureName);

	return new core::Sprite(texture, scale);
}
