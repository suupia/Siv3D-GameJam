#pragma once
#include "../GameObject/MessageContentContainer.h"

class MessageContentContainerBuilder
{
	String path_;
public:
	MessageContentContainerBuilder(const String& path);
   MessageContentContainer build_message_content_container(GameManager& gm, const Font& font)const;
};
