#pragma once
#include "../GameObject//MessageContent.h"
#include "MessageReader.h"

class MessageContentPictureAttacher
{
public:
	MessageContentPictureAttacher();
	Array<MessageContentStruct> create_message_content_struct(Array<MessageStruct> message_structs);
};
