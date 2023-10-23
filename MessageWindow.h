#pragma once
#include "GameManager.h"
#include "GameObject.h"

class MessageWindow : public GameObject
{
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;

	bool  is_displayed_full_text_ = false;

public:
	MessageWindow(GameManager& gm) : gm_(gm)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});
	}

	void open_message_window(const Font& font, const String& name, const String& message);

	void update_logic();
	void update_render();
};
