#pragma once
#include <string>
#include "core/graphics/font.h"
#include "core/math.h"

class Text
{
private:
	std::string text;
	float angleDegrees = 0;
	int color = 0xFFFFFFFF;
	uint8_t layer;
	Font font;

public:
	Text(const std::string &text, uint8_t layer, int color, Font font);
	void Draw(Vector2 position);

	void SetText(const std::string &text);
	const std::string GetText();
	int GetColor();
	Font GetFont();
	float GetAngleDegrees();

	static Text * Create(const std::string & text, const std::string & fontName, int color, uint8_t size, uint8_t layer, bool bold, bool italic);
};
