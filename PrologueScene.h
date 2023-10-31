#pragma once
#include "GameManager.h"
#include "MessageContentContainer.h"
#include "SceneSetting.h"

class PrologueScene : public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
	std::unique_ptr<MessageContentContainer> message_window_container_;
public:

	PrologueScene(const InitData& init, GameManager& gm, const Font& font);

	PrologueScene(const InitData& init);

	void update() override;

	void draw() const override;
};
