#include "stdafx.h"
#include "MessageContent.h"

#include "RectFUtility.h"

// private
void  MessageContent::show_message_window(const String& name, const String& message) const
{
	// texture
	(void)standing_picture_.draw(  Arg::center( Scene::Width() / 2, Scene::Height() / 2));

	// back ground box
	const auto back_ground_rect = RectFUtility::calc_relative_rect(0, 3.0/5.0, 1, 2.0/5.0).draw(Palette::Lightslategray);

	// message box
	const auto message_rect= RectFUtility::to_horizontal_center( RectF{back_ground_rect.x, back_ground_rect.y, back_ground_rect.w * 0.8, back_ground_rect.h} );
	(void)message_rect.draw(Palette::Lightblue);
	font_(message).draw(Arg::topLeft(message_rect.x + message_rect.w * 0.1, message_rect.y + message_rect.h * 0.2), Palette::Black);  // message_rectをそのまま使って場所を決めているわけではないことに注意

	// name box
	const auto rect = RectFUtility::calc_relative_rect(1.0/30.0,21.0/40.0,1.0/4.0,1.0/8.0);
	(void)rect.draw(Palette::Teal);
	font_(name).drawAt(RectFUtility::calc_center_pos(rect), Palette::White);
}

// public
void MessageContent::update_logic()
{
	// update logic
	if(is_waiting_for_input_) return;

	if(timer <= interval_second_)
	{
		timer +=  Scene::DeltaTime();
		if(timer >= interval_second_)
		{
			message_char_index_++;
			if(current_message_.size() <= message_char_index_) message_char_index_ =  static_cast<int>(current_message_.size()) - 1;
			timer = 0;
		}
	}

	if(message_char_index_ == current_message_.size() - 1) is_waiting_for_input_ = true;

}

static String insert_enter(const String& message)
{
	constexpr  int max_char_count = 25;
	int counter = 0;
	String result;
	for(auto i = 0; i < message.size(); i++)
	{
		result += message[i];
		if(message[i] == U'\n') counter = 0;
		if(counter % max_char_count == max_char_count -1) result += U"\n";
		counter ++;
	}
	return result;
}

void MessageContent::update_render()
{
	auto message = current_message_.substr(0, message_char_index_);
	message = insert_enter(message);
	show_message_window(name_, message);
}

void MessageContent::go_to_next_message()
{
	if(is_waiting_for_input_)
	{
		// start feeding the next message
		current_split_message_index_++;
		if(current_split_message_index_ >= split_messages_.size()) current_split_message_index_ = split_messages_.size() - 1;
		current_message_ = split_messages_[current_split_message_index_];
		message_char_index_ = 0;
		is_waiting_for_input_ = false;

		// raise flag to showed all messages
		if(current_split_message_index_ == split_messages_.size() - 1) is_showing_all_message_ = true;

	}else
	{
		// skip the current message feeding
		message_char_index_= static_cast<int>(current_message_.size()) - 1;
	}
}
