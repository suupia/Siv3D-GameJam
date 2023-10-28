# include <Siv3D.hpp> // OpenSiv3D v0.6.11
# include "MessageContent.h"
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

	set_up_window();

	// Register Assets
	TextureAsset::Register(U"Takeshi", U"images/takeshi_tmp.png");
	TextureAsset::Register(U"Founder", U"images/founder_tmp.png");
	TextureAsset::Register(U"PhotoStudio", U"images/photo_studio.png") ;

	MessageWindowContainer message_window_container(gm, font);
	message_window_container.add_message_window(
		MessageContent(font,
		              MessageContentStruct{
			              .name = U"創設者",
			              .messages =
			              U"やあ、よく来たね。\n私が見込んだ新入りさん。~ここは写真館《死の淵》だ。\nその名の通り、ここは死の淵と言って……~え？あなた誰って言った？~私のことを語るには、映画7本分の尺が必要になるけど……。~うーん、そんな露骨に嫌な顔しないで。\n君、本当に分かりやすいね。",
			              .standing_picture = TextureAsset(U"Founder"),
		              }));
	message_window_container.add_message_window(
		MessageContent(font,
		              MessageContentStruct{
			              .name = U"タケシ",
			              .messages = U"ここはどこだ、、？~俺はさっきまで雪山にいたはずだ、、~いったい何が起きたんだ。\nここは館みたいだが、、",
			              .standing_picture = TextureAsset(U"Takeshi"),
		              }));

	while (System::Update())
	{
		// draw background
		(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);


		if(KeySpace.down()) message_window_container.go_to_next_message();

		// message_window.update_logic();
		// message_window.update_render();
		message_window_container.update_logic();
		message_window_container.update_render();
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
