#pragma once
#include "../GameManager/GameManager.h"
#include "../GameObject//MessageContentContainer.h"
#include "SceneSetting.h"

class Episode1MultiEndScene: public SceneManager<SceneState, SceneData>::Scene
{
public:
	Episode1MultiEndScene(const InitData& init);
	void update() override;
	void draw() const override;
private:
	GameManager gm_;
	Font font_;
	MessageContentContainer  message_content_container_;

};
