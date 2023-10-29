#pragma once
#include "MessageWindowContainer.h"
#include "SceneSetting.h"

class PrologueScene : public SceneManager<SceneState, SceneData>::Scene
{
private:
	GameManager gm_;
	Font font_;
	std::unique_ptr<MessageWindowContainer> message_window_container_;
public:

	PrologueScene(const InitData& init, GameManager& gm, const Font& font);

	PrologueScene(const InitData& init);

	void update() override;

	void draw() const override;
};
