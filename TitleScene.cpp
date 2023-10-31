#include "stdafx.h"
#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init): IScene(init)
{
	// back ground
	TextureAsset::Register(U"Windmill", U"example/windmill.png");
}

void TitleScene::update(){
}

void TitleScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);
}
