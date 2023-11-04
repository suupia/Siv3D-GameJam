#pragma once

class Button
{
public:
	Button(const RectF& rect, const Font& font, const String& text);
	Button(const RectF& rect, const Font& font, const String& text, const String& texture_path);
	Button(const RectF& rect, const String& texture_path);
	Button(const RectF& rect, const double angle, const String& texture_path);

	bool is_down() const;
	void draw() const ;
	RectF get_rect() const { return rect_; }
private:
	RectF rect_;
	const double angle_ = 0;
	const Font font_;
	const String text_;
	const Optional<String> texture_key_ = none;
};
