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
	Array<IdentifyPhotoData> identify_photo_data_;
	int current_page_;
	void detect_button();

};
