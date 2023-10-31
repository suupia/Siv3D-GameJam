#include "stdafx.h"
#include "Episode1Scene.h"
#include "MessageContentPictureAttacher.h"


namespace
{
	MessageContentContainer build_message_content_container(GameManager& gm, const Font& font)
	{
		MessageContentContainer message_content_container(gm, font);

		const auto message_structs = MessageReader(U"texts/sc_Takeshi_1.txt" ).readMessageAll();
		const auto message_content_structs = MessageContentPictureAttacher().create_message_content_struct(message_structs);

		Array<MessageContent> message_contents;
		for(auto content_struct : message_content_structs)
		{
			message_contents.push_back(MessageContent(font,content_struct));
		}
		message_content_container.add_message_contents(message_contents);

		return message_content_container;
	}
}


Episode1Scene::Episode1Scene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	message_content_container_(build_message_content_container(gm_, font_))
{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;

}

void Episode1Scene::update(){

	message_content_container_.update_logic();

	if(KeySpace.down()) message_content_container_.go_to_next_message();
}

void Episode1Scene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	message_content_container_.update_render();


}
