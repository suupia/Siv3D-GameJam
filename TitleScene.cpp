#include "stdafx.h"
#include "TitleScene.h"

#include "RectFUtility.h"

TitleScene::TitleScene(const InitData& init): IScene(init), gm_(GameManager()), font_{ FontMethod::MSDF, 48 }
{
	// back ground
	TextureAsset::Register(U"Windmill", U"example/windmill.png");
}

void TitleScene::update(){
}

void TitleScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	const auto message_rect= RectFUtility::to_horizontal_center( RectF{50,100,Scene::Width(),Scene::Height()} );
	font_(U"写真館<<黄泉の前>>").drawAt(Scene::Width() / 2, Scene::Height() / 2, Palette::Black);

}
