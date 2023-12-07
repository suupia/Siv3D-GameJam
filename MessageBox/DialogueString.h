#pragma once
#include "MessageString.h"

struct DialogueString
{
	Array<MessageString> messages;

	DialogueString(const Array<MessageString>& messages)
		: messages(messages)
	{
	}
};
