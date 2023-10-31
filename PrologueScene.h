#pragma once
#include "GameManager.h"
#include "MessageContentContainer.h"
#include "SceneSetting.h"

class PrologueScene : public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
	MessageContentContainer  message_content_container_;
public:

	PrologueScene(const InitData& init);

	void update() override;

	void draw() const override;
};
