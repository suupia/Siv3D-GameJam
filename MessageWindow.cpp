﻿#include "stdafx.h"
#include "MessageWindow.h"

#include "RectFUtility.h"


void  MessageWindow::open_message_window(const Font& font , const String& name, const String& message)
{
	// back ground box
	const auto back_ground_rect = RectFUtility::calc_relative_rect(0, 3.0/5.0, 1, 2.0/5.0).draw(Palette::Lightslategray);

	// message box
	const auto message_rect= RectFUtility::to_horizontal_center( RectF{back_ground_rect.x, back_ground_rect.y, back_ground_rect.w * 0.8, back_ground_rect.h} );
	(void)message_rect.draw(Palette::Lightblue);
	font(message).drawAt(RectFUtility::calc_center_pos(message_rect), Palette::Black);

	// name box
	const auto rect = RectFUtility::calc_relative_rect(1.0/30.0,21.0/40.0,1.0/4.0,1.0/8.0);
	(void)rect.draw(Palette::Teal);
	font(name).drawAt(RectFUtility::calc_center_pos(rect), Palette::White);

}

void MessageWindow::update_logic()
{
}

void MessageWindow::update_render()
{
}
