#pragma once
#include "../GameManager/GameManager.h"
#include "../Button/Button.h"
#include "SceneSetting.h"

class Episode1FinalPhotoScene: public SceneManager<SceneState, SceneData>::Scene
{
public:
	Episode1FinalPhotoScene(const InitData& init);
	void update() override;
	void draw() const override;
private:
	GameManager  gm_;
	Font font_;

	Button next_page_button_;
	Button back_page_button_;

	void detect_button();
	void turn_page(bool is_next);

};
