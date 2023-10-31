#pragma once
#include "GameManager.h"
#include "GameObject.h"

struct MessageContentStruct {
	const String name;
	const String messages;
	const TextureAsset standing_picture;
};

class MessageContent : public GameObject
{
private:
	const Font& font_;

	const String name_;
	const String messages_;
	const TextureAsset standing_picture_;

	int message_char_index_ = 0;
	String current_message_;
	float interval_second_ = 0.07f;
	double timer = 0.0f;

	bool is_waiting_for_input_ = false;
	bool is_showing_all_message_ = false;

	void show_message_window(const String& name, const String& message) const;


public:
	MessageContent(const Font& font,
		const MessageContentStruct& message_window_struct
		) : font_(font),
	name_(message_window_struct.name),
	messages_(message_window_struct.messages),
	standing_picture_(message_window_struct.standing_picture)
	{

	}

	~MessageContent() = default;

	void update_logic() override;
	void update_render() const override;

	void show_all_message();
	[[nodiscard]]
	bool is_show_all_message() const { return is_showing_all_message_; }  // 実装ファイルに書いた方がよい？
};
