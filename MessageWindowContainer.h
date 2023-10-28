#pragma once
#include "GameManager.h"
#include "GameObject.h"
#include "MessageContent.h"

class MessageWindowContainer : public GameObject
{
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;
	const Font& font_;

	Array<MessageContent> message_windows_;
	int current_message_window_index_ = 0;

public:
	MessageWindowContainer(GameManager& gm, const Font& font
		) : gm_(gm), font_(font)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});
	}

	~MessageWindowContainer()
	{
		gm_.unregister_logic(logic_id_);
		gm_.unregister_render(render_id_);
	}

	void update_logic() override;
	void update_render() override;

	void add_message_window(const MessageContent& message_window_struct);
	void go_to_next_message();
};
