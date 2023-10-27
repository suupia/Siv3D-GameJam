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

	int message_char_index_ = 0;
	int current_split_message_index_ = 0;
	String current_message_;
	Array<String> split_messages_;
	float interval_second_ = 0.07f;
	double timer = 0.0f;

	bool is_waiting_for_input_ = false;

	void show_message_window(const String& name, const String& message) const;


public:
	MessageWindow(GameManager& gm, const Font& font) : gm_(gm), font_(font)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});

		split_messages_ = message_.split(U'~');
		current_message_ = split_messages_[0];
	}

	~MessageWindow()
	{
		gm_.unregister_logic(logic_id_);
		gm_.unregister_render(render_id_);
	}

	void update_logic() override;
	void update_render() override;

	void open_message_window(const String& name, const String& message);
};
