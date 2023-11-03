#pragma once
#include "../GameManager/GameManager.h"
#include "../Button/Button.h"
#include "SceneSetting.h"

class IdentifyPartScene : public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
	Array<Button> buttons_;
	Array<bool> is_selected_array;
	Array<RectF> sticky_note_poss_;

public:
	IdentifyPartScene(const InitData& init);

	void update() override;

	void draw() const override;

};
