#include "stdafx.h"
#include "MessageContentContainerBuilder.h"

#include "MessageContentPictureAttacher.h"
#include "MessageReader.h"


MessageContentContainer MessageContentContainerBuilder::build_message_content_container(GameManager& gm, const Font& font) const
{
	MessageContentContainer message_content_container(gm, font);

	const auto message_structs = MessageReader(path_).readMessageAll();
	const auto message_content_structs = MessageContentPictureAttacher().create_message_content_struct(message_structs);

	Array<MessageContent> message_contents;
	for (auto content_struct : message_content_structs)
	{
		message_contents.push_back(MessageContent(font, content_struct));
	}
	message_content_container.add_message_contents(message_contents);

	return message_content_container;
}

