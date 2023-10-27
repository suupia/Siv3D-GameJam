# include <Siv3D.hpp> // OpenSiv3D v0.6.11
# include "MessageWindow.h"
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

	set_up_window();

	const String name = U"Temp Name";
	const String messages = U"こんにちは。\nようこそ<<死の淵>>へ。~私はあなたのガイドです。~ここには何かしらの後悔や不満を抱えたまま瀕死の状態となった人が訪れます。";

	MessageWindow message_window(gm,font,name,messages);



	// Register Assets
	TextureAsset::Register(U"Takeshi", U"images/takeshi_tmp.png");
	TextureAsset::Register(U"Founder", U"images/founder_tmp.png");
	TextureAsset::Register(U"PhotoStudio", U"images/photo_studio.png");


	while (System::Update())
	{
		TextureAsset(U"PhotoStudio").resized(1920,1080).draw(0, 0);
		// message_window.open_message_window(font, name, message);
		if(KeySpace.down()) message_window.open_message_window();

		message_window.update_logic();
		message_window.update_render();

	 	TextureAsset(U"Takeshi").draw(40, 40);
		TextureAsset(U"Founder").draw(120,  40);
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
