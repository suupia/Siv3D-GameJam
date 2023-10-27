#pragma once
#include "GameManager.h"
#include "GameObject.h"
#include "MessageWindow.h"

class MessageWindowContainer : public GameObject
{
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;
	const Font& font_;

	Array<MessageWindowStruct> message_window_structs_;

public:
	MessageWindowContainer(GameManager& gm, const Font& font,
		const MessageWindowStruct& message_window_struct
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

	void add_message_window(const MessageWindowStruct& message_window_struct);

};
