#pragma once
#include "GameManager.h"
#include "GameObject.h"
#include "MessageContent.h"


class MessageContentContainer : public GameObject
{
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;
	const Font& font_;

	Array<MessageContent> message_contents_;
	int current_message_content_index_ = 0;

public:
	MessageContentContainer(GameManager& gm, const Font& font
		) : gm_(gm), font_(font)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});
	}

	~MessageContentContainer()
	{
		gm_.unregister_logic(logic_id_);
		gm_.unregister_render(render_id_);
	}

	void update_logic() override;
	void update_render() const override;

	void add_message_contents(const Array<MessageContent>& message_content_structs);
	void go_to_next_message();

};
