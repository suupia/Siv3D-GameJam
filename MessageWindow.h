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

    // temp
	const String name_ = U"Temp Name";
	const String message_ = U"こんにちは。\nようこそ<<死の淵>>へ。~私はあなたのガイドです。~ここには何かしらの後悔や不満を抱えたまま瀕死の状態となった人が訪れます。";

	int current_message_index_ = 0;
	String current_message_;
	float interval_second_ = 0.07f;
	double timer = 0.0f;

	bool is_waiting_for_input_ = false;

	void open_message_window(const String& name, const String& message) const;


public:
	MessageWindow(GameManager& gm, const Font& font) : gm_(gm), font_(font)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});

		current_message_ = message_;
	}

	~MessageWindow()
	{
		gm_.unregister_logic(logic_id_);
		gm_.unregister_render(render_id_);
	}

	void update_logic() override;
	void update_render() override;
};
