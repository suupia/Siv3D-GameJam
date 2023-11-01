#include "../stdafx.h"
#include "Episode1Scene.h"
#include "../MessageBox/MessageContentContainerBuilder.h"
#include "../GameManager/GameManager.h"

Episode1Scene::Episode1Scene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	message_content_container_(MessageContentContainerBuilder(U"texts/sc_Takeshi_1.txt" ).build_message_content_container(gm_, font_))
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
