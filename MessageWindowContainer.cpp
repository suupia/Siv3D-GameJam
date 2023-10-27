#include "stdafx.h"
#include "MessageWindowContainer.h"

void MessageWindowContainer::add_message_window(const MessageWindowStruct& message_window_struct)
{
	message_window_structs_.push_back(message_window_struct);
}

void MessageWindowContainer::update_logic()
{
	// for (auto& message_window_struct : message_window_structs_)
	// {
	// 	message_window_struct.message_window->update_logic();
	// }
}

void MessageWindowContainer::update_render()
{
	// for (auto& message_window_struct : message_window_structs_)
	// {
	// 	message_window_struct.message_window->update_render();
	// }
}
