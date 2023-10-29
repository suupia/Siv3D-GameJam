#pragma once
#include "GameManager.h"
#include "SceneSetting.h"

class TitleScene: public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
public:
	TitleScene(const InitData& init);

	void update() override;

	void draw() const override;
};
