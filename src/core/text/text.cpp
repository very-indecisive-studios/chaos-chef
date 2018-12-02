#include "text.h"
#include "context.h"

Text::Text(const std::string &text, uint8_t layer, int color, Font font)
	: text(text), layer(layer), color(color), font(font)
{ }

void Text::Draw(Vector2 position)
{
	DrawTextJob *job = new DrawTextJob(this, position, layer);

	Context::Get()->GetGraphicsRenderer()->QueueDrawJob(job);
}

void Text::SetText(const std::string& text)
{
	this->text = text;
}

const std::string Text::GetText()
{
	return this->text;
}

int Text::GetColor()
{
	return this->color;
}

void Text::SetColor(int color)
{
	this->color = color;
}

Font Text::GetFont()
{
	return this->font;
}

float Text::GetAngleDegrees()
{
	return this->angleDegrees;
}

Text * Text::Create(
	const std::string& text, 
	const std::string& fontName,
	int color,
	uint8_t size,  
	uint8_t layer,
	bool bold,
	bool italic
)
{
	UINT weight = FW_NORMAL;
	if (bold) 
	{
		weight = weight | FW_BOLD;
	}

	Font font = Context::Get()->GetGraphicsRenderer()->LoadFont(fontName, size, weight, italic);
	return new Text(text, layer, color, font);
}