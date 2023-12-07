#include "../stdafx.h"
#include "MessageContentContainerBuilder.h"

#include "MessageContentPictureAttacher.h"
#include "SingleDialogueReader.h"

MessageContentContainerBuilder::MessageContentContainerBuilder(const String& path) :
	path_(path)
{
}

MessageContentContainer MessageContentContainerBuilder::build_message_content_container(GameManager& gm, const Font& font) const
{
	MessageContentContainer message_content_container(gm, font);

	const auto dialogue_string = SingleDialogueReader(path_).readMessageAll();
	const auto dialogue_with_texture = MessageContentPictureAttacher().create_message_content_struct(dialogue_string);

	Array<MessageContent> message_contents;
	for (auto content_struct : dialogue_with_texture.message_with_textures)
	{
		message_contents.push_back(MessageContent(font, content_struct));
	}
	message_content_container.add_message_contents(message_contents);

	return message_content_container;
}

