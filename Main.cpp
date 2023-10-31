# include <Siv3D.hpp> // OpenSiv3D v0.6.11
# include "MessageContent.h"
#include "MessageContentPictureAttacher.h"
#include "MessageReader.h"
#include "MessageWindowContainer.h"
# include "RectFUtility.h"

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

void Main()
{
	const Font font{ FontMethod::MSDF, 48 };
	GameManager gm;
	MessageReader message_reader;
	MessageContentPictureAttacher message_content_picture_attacher;

	set_up_window();

	// Register Assets
	TextureAsset::Register(U"Takeshi", U"images/takeshi_tmp.png");
	TextureAsset::Register(U"Founder", U"images/founder_tmp.png");
	TextureAsset::Register(U"PhotoStudio", U"images/photo_studio.png") ;
	TextureAsset::Register(U"Me", U"images/siv3d-kun.png");

	MessageWindowContainer message_window_container(gm, font);
	auto message_structs = message_reader.readMessageAll();

	auto message_content_structs = message_content_picture_attacher.create_message_content_struct(message_structs);

	Array<MessageContent> message_windows_;
	for(auto content_struct : message_content_structs)
	{
		message_windows_.push_back(MessageContent(font,content_struct));
	}

	message_window_container.add_message_contents(message_windows_);


	while (System::Update())
	{
		// draw background
		(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

		message_window_container.update_logic();
		message_window_container.update_render();

		if(KeySpace.down()) message_window_container.go_to_next_message();


		if(Key0.down())
		{
			Print <<  message_reader.readMessageOne().name;
			Print << message_reader.readMessageOne().messages;
		}
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
