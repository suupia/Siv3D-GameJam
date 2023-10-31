﻿# include <Siv3D.hpp> // OpenSiv3D v0.6.11
# include "MessageContent.h"
#include "PastPhotoButton.h"
#include "PrologueScene.h"
#include "MessageContentPictureAttacher.h"
#include "MessageReader.h"
#include "MessageContentContainer.h"
# include "RectFUtility.h"
#include "SceneSetting.h"
#include "TitleScene.h"

namespace
{
	void set_up_window()
	{
		constexpr  int windowWidth = 1920;
		constexpr  int windowHeight = 1080;
		if(windowWidth * 9 != windowHeight * 16)
		{
			throw Error(U"You should set the resolution to 16:9");
		}
		Window::Resize(windowWidth, windowHeight);
		Window::SetStyle(WindowStyle::Sizable);



		// Set Background Color
		Scene::SetBackground(ColorF{ 139/ 255.0f,69/ 255.0f,19/ 255.0f});
	}

	SceneManager<SceneState,SceneData> set_up_scene_manager()
	{
		SceneManager<SceneState,SceneData> scene_manager;
		scene_manager.add<TitleScene>(SceneState::Title);
		scene_manager.add<PrologueScene>(SceneState::Prologue);

		scene_manager.init(SceneState::Prologue);
		return  scene_manager;
	}

	MessageContentContainer build_message_content_container(GameManager& gm, const Font& font)
	{
		MessageContentContainer message_content_container(gm, font);

		const auto message_structs = MessageReader().readMessageAll();
	    const auto message_content_structs = MessageContentPictureAttacher().create_message_content_struct(message_structs);

		Array<MessageContent> message_contents;
		for(auto content_struct : message_content_structs)
		{
			message_contents.push_back(MessageContent(font,content_struct));
		}
		message_content_container.add_message_contents(message_contents);

		return message_content_container;
	}
}

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

void Main()
{
	const Font font{ FontMethod::MSDF, 48 };
	GameManager gm;

	set_up_window();

	// Scene Manager
	auto scene_manager = set_up_scene_manager();

	while (System::Update())
	{
		// // draw background
		// (void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);
		//
		//
		// if(KeySpace.down()) message_window_container.go_to_next_message();
		//
		// message_window_container.update_logic();
		// message_window_container.update_render();
		//
		//
		// // Cause Determination Part
		// past_photo_button.update_logic();
		// past_photo_button.update_render();

		if(Key1.pressed())
		{
			scene_manager.changeScene(SceneState::Title);
		}
		if(Key2.pressed())
		{
			scene_manager.changeScene(SceneState::Prologue);
		}

		if(not scene_manager.update()) break;

	}
}

//
// - Debug ビルド: プログラムの最適化を減らす代わりに、エラーやクラッシュ時に詳細な情報を得られます。
//
// - Release ビルド: 最大限の最適化でビルドします。
//
// - [デバッグ] メニュー → [デバッグの開始] でプログラムを実行すると、[出力] ウィンドウに詳細なログが表示され、エラーの原因を探せます。
//
// - Visual Studio を更新した直後は、プログラムのリビルド（[ビルド]メニュー → [ソリューションのリビルド]）が必要な場合があります。
//
