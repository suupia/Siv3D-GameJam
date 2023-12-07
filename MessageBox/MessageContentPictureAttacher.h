#pragma once
#include "../GameObject//MessageContent.h"
#include "SingleDialogueReader.h"

class MessageContentPictureAttacher
{
public:
	MessageContentPictureAttacher();
	Array<MessageContentStruct> create_message_content_struct(const DialogueString& dialogue_string);
};
