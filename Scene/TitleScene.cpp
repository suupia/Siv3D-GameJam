#include "../stdafx.h"
#include "TitleScene.h"
#include "../Utility/RectFUtility.h"

TitleScene::TitleScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48, U"fonts/ZenAntiqueSoft.ttf" },
	start_button_( RectFUtility::to_horizontal_center( RectFUtility::calc_relative_rect(0.5, 0.7, 0.1,0.08)), font_, U"はじめる")
{
	TextureAsset::Register(U"Title", U"images/title.png") ;
}

void TitleScene::update(){
	if(KeyA.down()) changeScene(SceneState::Prologue, 2.0s);

	if(start_button_.is_down())
	{
		Logger << U"start";
		changeScene(SceneState::Prologue, 2.0s);
	}


}

void TitleScene::draw() const {
	(void)TextureAsset(U"Title").resized(Scene::Width(),Scene::Height()).draw(0, 0);


	start_button_.draw();
}
