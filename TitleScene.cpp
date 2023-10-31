#include "stdafx.h"
#include "TitleScene.h"
#include "RectFUtility.h"

namespace
{
	bool Button(const Rect& rect, const Font& font, const String& text, bool enabled)
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
	// back ground
	TextureAsset::Register(U"Windmill", U"example/windmill.png");
}

void TitleScene::update(){
	if(KeyA.down()) changeScene(SceneState::Prologue, 2.0s);
}

void TitleScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	const auto message_rect= RectFUtility::to_horizontal_center( RectF{50,100,Scene::Width(),Scene::Height()} );
	font_(U"写真館<<黄泉の前>>").drawAt(Scene::Width() / 2, Scene::Height() / 2, Palette::Black);

}
