#include "stdafx.h"
#include "TitleScene.h"

#include "RectFUtility.h"

TitleScene::TitleScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	start_button_( RectFUtility::to_horizontal_center( RectFUtility::calc_relative_rect(0.5, 0.7, 0.1,0.08)), font_, U"はじめる")
{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;
}

void TitleScene::update(){
	if(KeyA.down()) changeScene(SceneState::Prologue, 2.0s);

	if(start_button_.is_down())
	{
		Print << U"start";
		changeScene(SceneState::Prologue, 2.0s);
	}


}

void TitleScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	font_(U"写真館<<黄泉の前>>").drawAt(Scene::Width() / 2, Scene::Height() / 2, Palette::Black);

	start_button_.draw();
}
