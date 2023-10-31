#include "stdafx.h"
#include "MessageContentPictureAttacher.h"

#include "MessageReader.h"


MessageContentPictureAttacher::MessageContentPictureAttacher()
{
	TextureAsset::Register(U"Takeshi", U"images/takeshi_tmp.png");
	TextureAsset::Register(U"Founder", U"images/founder_tmp.png");
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;
	TextureAsset::Register(U"Me", U"images/siv3d-kun.png");

}

Array<MessageContentStruct> MessageContentPictureAttacher::create_message_content_struct(Array<MessageStruct> message_structs)
{
	Print << U"create_message_content_struct";
	Array<MessageContentStruct> result;

	for(auto content : message_structs)
	{
		TextureAsset person_picture = TextureAsset(U"Me");
		if (content.name == U"創設者")
			person_picture = TextureAsset(U"Founder");
		else if (content.name == U"Takeshi")
			person_picture = TextureAsset(U"Takeshi");
		else
			throw Error(U"Unexpected name name:{}\nThe name of the text file may be incorrect."_fmt(content.name));

		result.push_back({content.name, content.messages, person_picture});
	}
	return result;
}
