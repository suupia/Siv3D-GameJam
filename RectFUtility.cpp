#include "stdafx.h"
#include "RectFUtility.h"

RectF RectFUtility::calc_relative_rect(double offset_x, double offset_y, double width, double height)
{
	return RectF{ offset_x * Scene::Width(), offset_y * Scene::Height(), width * Scene::Width(), height * Scene::Height() };
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
