#pragma once
#include "MessageWithTexture.h"

struct DialogueWithTexture
{
	Array<MessageWithTexture> message_with_textures;

	DialogueWithTexture(const Array<MessageWithTexture>& messages)
		: message_with_textures(messages)
	{
	}
};
