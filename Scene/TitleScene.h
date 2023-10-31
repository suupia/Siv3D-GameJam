#pragma once
#include "../Button/Button.h"
#include "../GameManager/GameManager.h"
#include "SceneSetting.h"

class TitleScene: public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
	Button start_button_;
public:
	TitleScene(const InitData& init);

	void update() override;

	void draw() const override;
};
