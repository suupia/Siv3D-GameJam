#pragma once

static  class RectFUtility
{
public:
	static RectF calc_relative_rect(double offset_x, double offset_y, double width, double height);

	static Vec2 calc_center_pos(const RectF& rect);

	// Transform coordinates to be centered horizontally
	static RectF to_horizontal_center(const RectF& rect);


};
