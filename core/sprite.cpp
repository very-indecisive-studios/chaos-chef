#include "sprite.h"
#include "context.h"

core::Sprite::Sprite(Texture *&texture, int scale)
{
	this->texture = texture;
	this->scale = scale;
	this->width = texture->GetWidth() * scale;
	this->height = texture->GetHeight() * scale;
}

core::Sprite::~Sprite()
{
	// Don't delete texture here. Other sprites may have reference to the texture.
	// Leave the deletion of texture to resource manager.
}

void core::Sprite::Draw(core::Vector2 position)
{
	auto graphicsRenderer
			= core::Context::Get()->GetGraphicsRenderer();

	core::SpriteDrawJob *job = new SpriteDrawJob();
	job->pos = position;
	job->sprite = this;

	graphicsRenderer->QueueSpriteDrawJob(job);
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

core::Texture * core::Sprite::GetTexture()
{
	return this->texture;
}

core::Sprite * core::Sprite::Create(const std::string& textureName, int scale) {
	auto texture 
		= core::Context::Get()->GetResourceManager()->GetTexture(textureName);

	Sprite *sprite = new core::Sprite(texture, scale);
	return sprite;
}
