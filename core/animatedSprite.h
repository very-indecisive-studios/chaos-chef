#pragma once

#include "sprite.h"

namespace core {
	class AnimatedSprite : Sprite {
	private:
		int secondsPerFrame = 60;
		bool isPlaying = false;
		
		int totalFrames;
		int framesPerCol;
		int framesPerRow;
		int currentFrameCol = 0;
		int currentFrameRow = 0;

		float secondsPassed = 0;

		void NextFrame();
	public:
		AnimatedSprite(Texture *texture, int frameWidth, int frameHeight, int secondsPerFrame, int scale = 1);
		void Update(float deltaTime);
		void UpdateAndDraw(float deltaTime, Vector2 position);
		void Play();
		void Reset();
		void Stop();

		static AnimatedSprite * Create(const std::string &textureName, int frameWidth, int frameHeight, int secondsPerFrame, int scale = 1);
	};
}