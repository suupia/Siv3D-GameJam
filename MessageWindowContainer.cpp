#include "stdafx.h"
#include "MessageWindowContainer.h"

void MessageWindowContainer::add_message_window(const MessageWindow& message_window_struct)
{
	message_windows_.push_back(message_window_struct);
}

void MessageWindowContainer::update_logic()
{
	message_windows_[current_message_window_index_].update_logic();
}

void MessageWindowContainer::update_render()
{
	message_windows_[current_message_window_index_].update_render();
}

void MessageWindowContainer::go_to_next_message()
{
	message_windows_[current_message_window_index_].go_to_next_message();
}
