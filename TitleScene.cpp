#include "stdafx.h"
#include "TitleScene.h"
#include "RectFUtility.h"

namespace
{
	bool Button(const RectF& rect, const Font& font, const String& text, bool enabled)
	{
		if (enabled && rect.mouseOver())
		{
			Cursor::RequestStyle(CursorStyle::Hand);
		}

		if (enabled)
		{
			rect.draw(ColorF{ 0.3, 0.7, 1.0 });
			font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2));
		}
		else
		{
			rect.draw(ColorF{ 0.5 });
			font(text).drawAt(40, (rect.x + rect.w / 2), (rect.y + rect.h / 2), ColorF{ 0.7 });
		}

		return (enabled && rect.leftClicked());
	}
}

TitleScene::TitleScene(const InitData& init): IScene(init),gm_(GameManager()),font_{FontMethod::MSDF, 48}
{
}

void TitleScene::update(){
	if(KeyA.down()) changeScene(SceneState::Prologue, 2.0s);


}

void TitleScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	font_(U"写真館<<黄泉の前>>").drawAt(Scene::Width() / 2, Scene::Height() / 2, Palette::Black);

	if(	Button(RectF{Scene::Width() / 2, Scene::Height() / 2 + 100, 200, 100}, font_, U"はじめる", true))
	{
		Print << U"はじめる";
	}


}
