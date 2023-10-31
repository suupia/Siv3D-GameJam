#include "stdafx.h"
#include "Button.h"

namespace
{
	bool Button(const RectF& rect, const Font& font, const String& text, bool enabled)
	{
		if (enabled && rect.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
		}

		if (enabled)
		{
			rect.draw(ColorF{ 0.3, 0.7, 1.0 });
			font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2));
		}
		else
		{
			rect.draw(ColorF{ 0.5 });
			font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2), ColorF{ 0.7 });
		}

		return (enabled && rect.leftClicked());
	}
}

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
	rect_.draw();
}
