#pragma once
#include "MessageContentContainer.h"

class MessageContentContainerBuilder
{
	String path_;
public:
	MessageContentContainerBuilder(String path);
   MessageContentContainer build_message_content_container(GameManager& gm, const Font& font)const;
};
