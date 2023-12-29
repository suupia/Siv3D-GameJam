#include "../stdafx.h"
#include "Episode1AnswerScene.h"
#include "../MessageBox/MessageContentContainerBuilder.h"
#include "../GameManager/GameManager.h"

Episode1AnswerScene::Episode1AnswerScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48, U"fonts/ZenAntiqueSoft.ttf" },
	message_content_container_(MessageContentContainerBuilder(U"texts/sc_Takeshi_2.json" ).build_message_content_container(gm_, font_))
{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;

}

void Episode1AnswerScene::update(){

	message_content_container_.update_logic();

	if(KeySpace.down() || MouseL.down())
	{
		if (message_content_container_.is_message_finished())
		{
			changeScene(SceneState::Episode1FinalPhoto);
		}
		else
		{
			message_content_container_.go_to_next_message();
		}
	}
}

void Episode1AnswerScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	message_content_container_.update_render();

}
