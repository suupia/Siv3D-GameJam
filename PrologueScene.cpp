#include "stdafx.h"
#include "PrologueScene.h"
#include "MessageContentContainer.h"
#include "PastPhotoButton.h"


PrologueScene::PrologueScene(const InitData& init) : IScene(init), gm_(GameManager()), font_{ FontMethod::MSDF, 48 }
{
	Print << U"Constructed PrologueScene";

	message_window_container_  = std::make_unique<MessageContentContainer>(gm_, font_);

}

void PrologueScene::update()
{
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);
}

void PrologueScene::draw() const
{
}
