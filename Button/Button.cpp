#include "../stdafx.h"
#include "Button.h"

Button::Button(const RectF& rect, const Font& font, const String& text)
	: rect_(rect), font_(font), text_(text)
{
}

Button::Button(const RectF& rect, const Font& font, const String& text, const String& texture_path)
	: rect_(rect), font_(font), text_(text), texture_key_(texture_path)
{
}

Button::Button(const RectF& rect,const String& texture_path)
	: rect_(rect),texture_key_(texture_path)
{
}

Button::Button(const RectF& rect, const double angle, const String& texture_path)
	: rect_(rect), angle_(angle), texture_key_(texture_path)
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
	if(texture_key_ == none)
	{
		rect_.rotated(angle_).draw(ColorF{ 191/255.0, 90/255.0, 86/255.0, 1.0 });
		(void)font_(text_).drawAt(40, (rect_.x + rect_.w / 2), (rect_.y + rect_.h / 2));
	}else
	{
		(void)TextureAsset(*texture_key_).resized(rect_.w, rect_.h).rotated(angle_).draw(rect_.x, rect_.y);
		(void)font_(text_).drawAt(40, (rect_.x + rect_.w / 2), (rect_.y + rect_.h / 2));
	}
}
