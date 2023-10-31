#pragma once
#include "Button.h"
#include "GameManager.h"
#include "SceneSetting.h"

class Episode1Scene: public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
public:
	Episode1Scene(const InitData& init);

	void update() override;

	void draw() const override;

};
