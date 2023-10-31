#pragma once

static  class RectFUtility
{
public:
	static RectF calc_relative_rect(double offset_x_ratio, double offset_y_ratio, double width_ratio, double height_ratio);

	static Vec2 calc_center_pos(const RectF& rect);

	// Transform coordinates to be centered horizontally
	static RectF to_horizontal_center(const RectF& rect);


};
