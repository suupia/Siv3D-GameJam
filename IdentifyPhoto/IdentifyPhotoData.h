#pragma once
#include "../Button/Button.h"

struct IdentifyPhotoData {
	const Button button;
	const RectF sticky_note_pos;
	const String caption_text;
	const RectF caption_rect;
	bool is_selected;
};
