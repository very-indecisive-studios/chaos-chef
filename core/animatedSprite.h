#pragma once

#include "sprite.h"

namespace core {
	class AnimatedSprite : public Sprite {
	private:
		float secondsPerFrame = 60.0f;
		bool isPlaying = false;
		
		int totalFrames;
		int framesPerCol;
		int framesPerRow;
		int currentFrameCol = 0;
		int currentFrameRow = 0;

		float secondsPassed = 0;

		void NextFrame();
	public:
		AnimatedSprite(Texture *texture, SpriteLayer layer, int frameWidth, int frameHeight, float secondsPerFrame, int scale = 1);
		void Update(float deltaTime);
		void UpdateAndDraw(float deltaTime, Vector2 position);
		void Play();
		void Reset();
		void Stop();

		static AnimatedSprite * Create(const std::string &textureName, SpriteLayer layer, int frameWidth, int frameHeight, float secondsPerFrame, int scale = 1);
	};
}