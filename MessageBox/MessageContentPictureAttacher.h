#pragma once
#include "DialogueWithTexture.h"
#include "../GameObject//MessageContent.h"
#include "SingleDialogueReader.h"

class MessageContentPictureAttacher
{
public:
	MessageContentPictureAttacher();
	DialogueWithTexture create_message_content_struct(const DialogueInfo& dialogue_string);
};
