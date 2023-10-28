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
	TextureAsset::Register(U"Me", U"images/siv3d-kun.png");

	MessageWindowContainer message_window_container(gm, font);
	message_window_container.add_message_content(
		MessageContent(font,
		               MessageContentStruct{
			               .name = U"創設者",
			               .messages =
			               U"やあ、よく来たね。\n私が見込んだ新入りさん。~ここは写真館《黄泉の前》だ。\nその名の通り、ここは死の淵と言って……~え？あなた誰って言った？~私のことを語るには、映画7本分の尺が必要になるけど……。~うーん、そんな露骨に嫌な顔しないで。\n君、本当に分かりやすいね。~まあ、とにかく。\n今はこの写真館の話をしよう。~さっきも言ったけど、ここは《黄泉の前》だ。\nだから、お客様もちょっと特殊でね。~理由は様々さ。ただ、1つ共通点を挙げるならば。\n彼らは《負の感情》を持ってここに来る。~君の仕事は、お客様の《負の感情》の原因を\n見つけてあげることだ。~……ん？なぜそんなことをするのか？\nとでも言いたげだね。~お客様の気持ちを考えてみてよ。~彼らは\"何が\"不満で、\"誰に\"悲しみを抱いたのか、まるで覚えてない。~生まれる方法は1つしか無いけど、死ぬ方法は何万通りもある。《黄泉の前》に来る。\nニンゲンだって同じだ。~それを「思い出せ」の一言で済ませるのは、あまりにも気の毒じゃないか？~幸い、私たちは彼らの人生を垣間見ることができる。\n彼らのアルバムが全て教えてくれるから。~さあ、とにかく始めてみよう。\n丁度、お客様も来たみたいだからね。",
			               .standing_picture = TextureAsset(U"Founder"),
		               }),

		MessageContent(font,
		               MessageContentStruct{
			               .name = U"タケシ",
			               .messages = U"あの、ここは一体……？\n僕、山登りに来ていたはずなんですが……。",
			               .standing_picture = TextureAsset(U"Takeshi"),
		               }),

		MessageContent(font,
		               MessageContentStruct{
			               .name = U"ワタシ",
			               .messages = U"ようこそ、ここは写真館《黄泉の前》です。",
			               .standing_picture = TextureAsset(U"Me"),
		               }),

		MessageContent(font,
		               MessageContentStruct{
			               .name = U"タケシ",
			               .messages = U"黄泉の前！？写真館！？",
			               .standing_picture = TextureAsset(U"Takeshi"),
		               }),

		MessageContent(font,
		               MessageContentStruct{
			               .name = U"ワタシ",
			               .messages = U"簡単に言うと、あなたは今ひん死状態なんです。\nここは、ひん死の人が来る場所なので。",
			               .standing_picture = TextureAsset(U"Me"),
		               }),

		MessageContent(font,
		               MessageContentStruct{
			               .name = U"タケシ",
			               .messages = U"おおー、だから《黄泉の前》なんですね！意味分かんないです！",
			               .standing_picture = TextureAsset(U"Takeshi"),
		               }),

		MessageContent(font,
		               MessageContentStruct{
			               .name = U"ワタシ",
			               .messages = U"確かに、意味を考え出すとアレかもしれませんが……。",
			               .standing_picture = TextureAsset(U"Me"),
		               })
	);

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
