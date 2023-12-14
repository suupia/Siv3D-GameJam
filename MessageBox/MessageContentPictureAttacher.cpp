#include "../stdafx.h"
#include "MessageContentPictureAttacher.h"

#include "DialogueWithTexture.h"
#include "SingleDialogueReader.h"


struct MessageWithTexture;

MessageContentPictureAttacher::MessageContentPictureAttacher()
{
	TextureAsset::Register(U"Takeshi_0", U"images/Takeshi_0.png");
	TextureAsset::Register(U"Founder", U"images/founder.png");
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;
	TextureAsset::Register(U"I", U"images/siv3d-kun.png");

}

DialogueWithTexture MessageContentPictureAttacher::create_message_content_struct(const DialogueString& dialogue_string)
{
	Logger << U"create_message_content_struct";
	auto message_strings = dialogue_string.messages;

	Array<MessageWithTexture> result;

	for(auto content : message_strings)
	{
		TextureAsset person_picture = TextureAsset(U"Me");
		if(content.name == U"ワタシ")
			person_picture = TextureAsset(U"I");
		else if (content.name == U"創設者")
			person_picture = TextureAsset(U"Founder");
		else if (content.name == U"たけし")
			person_picture = TextureAsset(U"Takeshi_0");
		else if (content.name == U"none")
			person_picture = TextureAsset(U"I");
		else
			throw Error(U"Unexpected name name:{}\nThe name of the text file may be incorrect."_fmt(content.name));

		result.push_back({content.name, content.message, person_picture});
	}

	return DialogueWithTexture(result);
}
