#pragma once
#include "GameManager.h"
#include "GameObject.h"

struct MessageWindowStruct {
	const String& name;
	const String& messages;
	const TextureAsset& standing_picture;
};

class MessageWindow : public GameObject
{
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;
	const Font& font_;

	const String& name_;
	const String& messages_;
	const TextureAsset& standing_picture_;

	int message_char_index_ = 0;
	int current_split_message_index_ = 0;
	String current_message_;
	Array<String> split_messages_;
	float interval_second_ = 0.07f;
	double timer = 0.0f;

	bool is_waiting_for_input_ = false;

	void show_message_window(const String& name, const String& message) const;


public:
	MessageWindow(GameManager& gm, const Font& font,
		const MessageWindowStruct& message_window_struct
		) : gm_(gm), font_(font),
	name_(message_window_struct.name),
	messages_(message_window_struct.messages),
	standing_picture_(message_window_struct.standing_picture)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});

		split_messages_ = messages_.split(U'~');
		current_message_ = split_messages_[0];
	}

	~MessageWindow()
	{
		gm_.unregister_logic(logic_id_);
		gm_.unregister_render(render_id_);
	}

	void update_logic() override;
	void update_render() override;

	void open_message_window();
};
