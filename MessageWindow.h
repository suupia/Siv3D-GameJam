#pragma once
#include "GameManager.h"
#include "GameObject.h"

class MessageWindow : public GameObject
{
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;
	const Font& font_;

	bool  is_displayed_full_text_ = false;


    // temp
	const String name_ = U"Temp Name";
	const String message_ = U"こんにちは。\nようこそ<<死の淵>>へ。";

	void open_message_window(const String& name, const String& message) const;


public:
	MessageWindow(GameManager& gm, const Font& font) : gm_(gm), font_(font)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});
	}

	void update_logic();
	void update_render();
};
