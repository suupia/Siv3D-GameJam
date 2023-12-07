#include "../stdafx.h"
#include "Episode1MultiEndScene.h"
#include "../MessageBox/MessageContentContainerBuilder.h"
#include "../GameManager/GameManager.h"

#include "../MessageBox/MessageContentPictureAttacher.h"
#include "../MessageBox/SingleDialogueReader.h"

namespace
{
	MessageContentContainer build_message_content_container(GameManager& gm, const Font& font, const int chosen_final_photo_index)
	{
		// This function must be in the MessageContentContainerBuilder.cpp !!!!!
		MessageContentContainer message_content_container(gm, font);

		// U"texts/sc_Takeshi_3.txt"
		const auto message_structs = SingleDialogueReader(U"texts/sc_Takeshi_3.txt").readMessageAll();
		const auto message_content_structs = MessageContentPictureAttacher().create_message_content_struct(message_structs);
		Array<MessageContent> message_contents;
		for (auto content_struct : message_content_structs)
		{
			message_contents.push_back(MessageContent(font, content_struct));
		}
		message_content_container.add_message_contents(message_contents);

		// U"texts/sc_Takeshi_End_x.txt"
		const auto message_structs1 = SingleDialogueReader(U"texts/sc_Takeshi_End_{}.txt"_fmt(chosen_final_photo_index)).readMessageAll();
		const auto message_content_structs1 = MessageContentPictureAttacher().create_message_content_struct(message_structs1);
		Array<MessageContent> message_contents1;
		for (auto content_struct : message_content_structs1)
		{
			message_contents1.push_back(MessageContent(font, content_struct));
		}
		message_content_container.add_message_contents(message_contents1);

		// U"texts/sc_Takeshi_4.txt"
		const auto message_structs2 = SingleDialogueReader(U"texts/sc_Takeshi_4.txt").readMessageAll();
		const auto message_content_structs2 = MessageContentPictureAttacher().create_message_content_struct(message_structs2);
		Array<MessageContent> message_contents2;
		for (auto content_struct : message_content_structs2)
		{
			message_contents2.push_back(MessageContent(font, content_struct));
		}
		message_content_container.add_message_contents(message_contents2);


		return message_content_container;
	}

}

Episode1MultiEndScene::Episode1MultiEndScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48, U"fonts/ZenAntiqueSoft.ttf" },
	message_content_container_(build_message_content_container(gm_, font_, getData().chosen_final_photo_index))
{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;

	// Print << U"chosen final photo index = " << getData().chosen_final_photo_index;

}

void Episode1MultiEndScene::update(){

	message_content_container_.update_logic();

	if(KeySpace.down() || MouseL.down())
	{
		if (message_content_container_.is_message_finished())
		{
			changeScene(SceneState::Title);
		}
		else
		{
			message_content_container_.go_to_next_message();
		}
	}
}

void Episode1MultiEndScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	message_content_container_.update_render();

}
