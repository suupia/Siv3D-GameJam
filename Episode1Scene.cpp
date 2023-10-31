#include "stdafx.h"
#include "Episode1Scene.h"

Episode1Scene::Episode1Scene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48}
{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;

}

void Episode1Scene::update(){


}

void Episode1Scene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);


}
