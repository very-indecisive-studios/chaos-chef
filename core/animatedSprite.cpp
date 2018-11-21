#include "animatedSprite.h"
#include "context.h"
#include <iostream>

core::AnimatedSprite::AnimatedSprite(
	Texture * texture, int frameWidth, int frameHeight, int secondsPerFrame, int scale
) : Sprite(texture, scale)
{
	this->width = frameWidth;
	this->height = frameHeight;
	this->secondsPerFrame = secondsPerFrame;
	
	this->drawingArea = { 0 };
	this->drawingArea.right = this->width;
	this->drawingArea.bottom = this->height;

	this->framesPerCol = texture->GetWidth() / frameWidth;
	this->framesPerRow = texture->GetHeight() / frameHeight;
}

void core::AnimatedSprite::Update(float deltaTime)
{
	if (!isPlaying)
	{
		return;
	}
	
	secondsPassed += deltaTime;

	// std::cout << "seconds passed: " << secondsPassed << std::endl;

	if ((int)secondsPassed >= secondsPerFrame) 
	{
		secondsPassed = 0;

		NextFrame();
	}
}

void core::AnimatedSprite::UpdateAndDraw(float deltaTime, core::Vector2 position) 
{
	Update(deltaTime);

	core::Sprite::Draw(position);
}

void core::AnimatedSprite::NextFrame() 
{
	// Next frame.
	if (this->currentFrameCol + 1 == framesPerCol) 
	{
		currentFrameCol = 0;
		
		if (this->currentFrameRow + 1 == framesPerRow)
		{
			currentFrameRow = 0;
		}
		else
		{
			currentFrameRow++;
		}
	}
	else
	{
		currentFrameCol++;
	}

	this->drawingArea.left		= currentFrameCol * width;
	this->drawingArea.top		= currentFrameRow * height;
	
	this->drawingArea.right		= (currentFrameCol * width) + width;
	this->drawingArea.bottom	= (currentFrameRow * height) + height;
}

void core::AnimatedSprite::Play()
{
	this->isPlaying = true;
}

void core::AnimatedSprite::Reset()
{
	currentFrameCol = 0;
	currentFrameRow = 0;
}

void core::AnimatedSprite::Stop()
{
	this->isPlaying = false;
}

core::AnimatedSprite * core::AnimatedSprite::Create(const std::string & textureName, int frameWidth, int frameHeight, int secondsPerFrame, int scale)
{
	auto texture
		= core::Context::Get()->GetResourceManager()->GetTexture(textureName);

	return new core::AnimatedSprite(texture, frameWidth, frameHeight, secondsPerFrame, scale);
}
