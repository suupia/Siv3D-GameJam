#include "../stdafx.h"
#include "PrologueScene.h"
#include "../MessageBox/MessageContentContainerBuilder.h"
#include "../GameObject/PastPhotoButton.h"

PrologueScene::PrologueScene(const InitData& init) :
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48, U"fonts/ZenAntiqueSoft.ttf" },
	message_content_container_(MessageContentContainerBuilder(U"texts/sc_prologue.txt" ).build_message_content_container(gm_, font_))
{
	Logger << U"Constructed PrologueScene";
}

void PrologueScene::update()
{
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	message_content_container_.update_logic();

	if(KeySpace.down() || MouseL.down())
	{
		if (message_content_container_.is_message_finished())
		{
			changeScene(SceneState::Episode1);
		}
		else
		{
			message_content_container_.go_to_next_message();
		}
	}
}

void PrologueScene::draw() const
{
	message_content_container_.update_render();

}
