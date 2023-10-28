#include "stdafx.h"
#include "MessageWindowContainer.h"


void MessageWindowContainer::update_logic()
{
	auto&  message_window = 	message_windows_[current_message_window_index_];
	message_window.update_logic();
	if(message_window .is_show_all_message())current_message_window_index_++;
}

void MessageWindowContainer::update_render()
{
	message_windows_[current_message_window_index_].update_render();
}

void MessageWindowContainer::go_to_next_message()
{
	message_windows_[current_message_window_index_].go_to_next_message();
}
