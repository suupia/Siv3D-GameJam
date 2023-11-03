#pragma once

class Button
{
	RectF rect_;
	const Font font_;
	const String text_;
	const Optional<String> texture_key_ = none;
public:

	Button(RectF rect, const Font& font, const String& text);
	Button(RectF rect, const Font& font, const String& text, const String& texture_path);

	bool is_down() const;
	void draw() const ;
};
