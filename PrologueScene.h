#pragma once
#include "SceneSetting.h"

class PrologueScene : public SceneManager<SceneState, SceneData>::Scene
{
public:
	PrologueScene(const InitData& init);

	void update() override;

	void draw() const override;
};
