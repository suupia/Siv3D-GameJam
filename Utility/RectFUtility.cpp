#include "../stdafx.h"
#include "RectFUtility.h"

RectF RectFUtility::calc_relative_rect(double offset_x_ratio, double offset_y_ratio, double width_ratio, double height_ratio)
{
	return RectF{ offset_x_ratio * Scene::Width(), offset_y_ratio * Scene::Height(), width_ratio * Scene::Width(), height_ratio * Scene::Height() };
}

Vec2 RectFUtility::calc_center_pos(const RectF& rect)
{
	return Vec2{ rect.x + rect.w / 2.0, rect.y + rect.h / 2.0 };
}

// Transform coordinates to be centered horizontally
RectF RectFUtility::to_horizontal_center(const RectF& rect)
{
	const auto h_margin = Scene::Width() - rect.w;
	return RectF{ h_margin /2.0 , rect.y, rect.w, rect.h };
}
