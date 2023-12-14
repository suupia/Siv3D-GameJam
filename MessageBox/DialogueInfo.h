#pragma once
#include "MessageInfo.h"

struct DialogueInfo
{
	Array<MessageInfo> messages;

	DialogueInfo(const Array<MessageInfo>& messages)
		: messages(messages)
	{
	}
};
