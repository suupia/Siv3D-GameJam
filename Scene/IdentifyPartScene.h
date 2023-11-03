#pragma once
#include "../GameManager/GameManager.h"
#include "../Button/Button.h"
#include "SceneSetting.h"

struct IdentifyPhotoData {
	const Button button;
	const RectF sticky_note_pos;
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
	Array<IdentifyPhotoData> identify_photo_data_;

};
