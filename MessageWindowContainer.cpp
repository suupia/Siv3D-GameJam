#include "stdafx.h"
#include "MessageWindowContainer.h"
#include "MessageContentPictureAttacher.h"

template void MessageWindowContainer::add_message_content<MessageContentStruct>(const MessageContentStruct&);

void MessageWindowContainer::update_logic()
{
	auto&  message_window = 	message_windows_.at(current_message_window_index_);
	message_window.update_logic();
}

void MessageWindowContainer::update_render()
{
	message_windows_.at(current_message_window_index_).update_render();
}

void MessageWindowContainer::go_to_next_message()
{
	auto& message_window = message_windows_.at(current_message_window_index_);
	if (message_window.is_show_all_message())
	{
		current_message_window_index_++;
		if (message_windows_.size() <= current_message_window_index_) current_message_window_index_ = message_windows_.
			size() - 1;
	}else
	{
		message_window.show_all_message();
	}
}
