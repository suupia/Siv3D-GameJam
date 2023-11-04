#include "../stdafx.h"
#include "MessageContentContainer.h"


void MessageContentContainer::update_logic()
{
	auto&  message_content = message_contents_.at(current_message_content_index_);
	message_content.update_logic();
}

void MessageContentContainer::update_render() const
{
	message_contents_.at(current_message_content_index_).update_render();
}

void MessageContentContainer::add_message_contents(const Array<MessageContent>& message_content_structs)
{
	for(auto content_struct : message_content_structs)
	{
		message_contents_.push_back(content_struct);
	}
}

void MessageContentContainer::go_to_next_message()
{
	auto& message_content = message_contents_.at(current_message_content_index_);
	if (message_content.is_show_all_message())
	{
		current_message_content_index_++;
		if (message_contents_.size() <= current_message_content_index_) current_message_content_index_ = message_contents_.
			size() - 1;
	}else
	{
		message_content.show_all_message();
	}
}

bool MessageContentContainer::is_message_finished() const
{
	auto& message_content = message_contents_.at(current_message_content_index_);
	return message_content.is_show_all_message()  && current_message_content_index_ >= message_contents_.size() - 1;
}

