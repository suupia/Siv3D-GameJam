#include "../stdafx.h"
#include "Button.h"

Button::Button(RectF rect, const Font& font, const String& text)
	: rect_(rect), font_(font), text_(text)
{
}

bool Button::is_down() const
{
	return (rect_.leftClicked());
}

void Button::draw() const
{
	if (rect_.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);
	}
	rect_.draw(ColorF{ 0.3, 0.7, 1.0 });
	(void)font_(text_).drawAt(40, (rect_.x + rect_.w / 2), (rect_.y + rect_.h / 2));
}
