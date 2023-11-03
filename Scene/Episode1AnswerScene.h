#pragma once
#include "../GameManager/GameManager.h"
#include "../GameObject//MessageContentContainer.h"
#include "SceneSetting.h"

class Episode1AnswerScene: public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
	MessageContentContainer  message_content_container_;
public:
	Episode1AnswerScene(const InitData& init);

	void update() override;

	void draw() const override;

};
