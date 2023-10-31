#pragma once
#include "GameManager.h"
#include "GameObject.h"

class PastPhotoButton : public GameObject
{
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;
	const Font& font_;

	const RectF rect_;
public:
	PastPhotoButton(GameManager& gm, const Font& font, const RectF& rect
	) : gm_(gm), font_(font), rect_(rect)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});
	}

	~PastPhotoButton()
	{
		gm_.unregister_logic(logic_id_);
		gm_.unregister_render(render_id_);
	}

	void update_logic() override;
	void update_render() const override;

};
