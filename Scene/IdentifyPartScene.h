#pragma once
#include "../GameManager/GameManager.h"
#include "../Button/Button.h"
#include "SceneSetting.h"

struct IdentifyPhotoData {
	const Button button;
	const RectF sticky_note_pos;
	const String caption_text;
	const RectF caption_rect;
	bool is_selected;
};

class IdentifyPartScene : public SceneManager<SceneState, SceneData>::Scene
{
public:
	IdentifyPartScene(const InitData& init);
	void update() override;
	void draw() const override;
private:
	GameManager gm_;
	Font font_;

	Button next_page_button_;
	Button back_page_button_;
	Button confirm_button_;
	Array<IdentifyPhotoData> identify_photo_data_;
	int current_page_ = 0;
	const int all_photo_number_ = 12;
	const int photo_number_per_row_ = 3;
	const int photo_number_per_col_ = 2;
	const int photo_number_per_page_ = photo_number_per_row_ * photo_number_per_col_;

	Effect effect_;

	void detect_button();
	void turn_page(bool is_next);
};
