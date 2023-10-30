﻿#pragma once
#include "GameManager.h"
#include "GameObject.h"
#include "MessageContent.h"
#include "MessageContentPictureAttacher.h"

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

	// void add_message_window(const MessageContent& message_window_struct);
	void go_to_next_message();

	void add_message_contents(const Array<MessageContent>& message_content_structs)
	{
		for(auto content_struct : message_content_structs)
		{
			message_windows_.push_back(content_struct);
		}
	}

	template<class... Args>
    void add_message_content(const Args&... args)
	{
		for(auto content_struct : std::initializer_list<MessageContentStruct>{args...})
		{
			message_windows_.push_back(MessageContent(font_,content_struct));
		}
	}
};
