#include "stdafx.h"
#include "TitleScene.h"

TitleScene::TitleScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	start_button_(RectF{
		              Scene::Width() / 2, Scene::Height() / 2 + 100, 200, 100
	              }, font_, U"はじめる")
{
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
