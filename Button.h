#pragma once

class Button
{
	RectF rect_;
	const Font& font_;
	const String& text_;
public:

	Button(RectF rect, const Font& font, const String& text);

	bool is_down() const;
	void draw() const ;
};
