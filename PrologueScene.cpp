#include "stdafx.h"
#include "PrologueScene.h"

#include "MessageContent.h"
#include "MessageWindowContainer.h"


PrologueScene::PrologueScene(const InitData& init) : IScene(init)
{
	Print << U"Constructed PrologueScene";

	// Register Assets
	TextureAsset::Register(U"Takeshi", U"images/takeshi_tmp.png");
	TextureAsset::Register(U"Founder", U"images/founder_tmp.png");
	TextureAsset::Register(U"PhotoStudio", U"images/photo_studio.png") ;
	TextureAsset::Register(U"Me", U"images/siv3d-kun.png");
	TextureAsset::Register(U"Book", U"images/book_tmp.png");

	gm_= std::make_unique<GameManager>();
	font_ = std::make_unique<Font>(FontMethod::MSDF, 48);

	message_window_container_ =  std::make_unique<MessageWindowContainer>(*gm_,*font_);
	message_window_container_->add_message_content(

		// MessageContentStruct{
		// 	.name = U"創設者",
		// 	.messages =
		// 	U"やあ、よく来たね。\n私が見込んだ新入りさん。~ここは写真館《黄泉の前》だ。\nその名の通り、ここは死の淵と言って……~え？あなた誰って言った？~私のことを語るには、映画7本分の尺が必要になるけど……。~うーん、そんな露骨に嫌な顔しないで。\n君、本当に分かりやすいね。~まあ、とにかく。\n今はこの写真館の話をしよう。~さっきも言ったけど、ここは《黄泉の前》だ。\nだから、お客様もちょっと特殊でね。~理由は様々さ。ただ、1つ共通点を挙げるならば。\n彼らは《負の感情》を持ってここに来る。~君の仕事は、お客様の《負の感情》の原因を\n見つけてあげることだ。~……ん？なぜそんなことをするのか？\nとでも言いたげだね。~お客様の気持ちを考えてみてよ。~彼らは\"何が\"不満で、\"誰に\"悲しみを抱いたのか、まるで覚えてない。~生まれる方法は1つしか無いけど、死ぬ方法は何万通りもある。《黄泉の前》に来る。\nニンゲンだって同じだ。~それを「思い出せ」の一言で済ませるのは、あまりにも気の毒じゃないか？~幸い、私たちは彼らの人生を垣間見ることができる。\n彼らのアルバムが全て教えてくれるから。~さあ、とにかく始めてみよう。\n丁度、お客様も来たみたいだからね。",
		// 	.standing_picture = TextureAsset(U"Founder"),
		// },

		// MessageContentStruct{
		// 	.name = U"タケシ",
		// 	.messages = U"あの、ここは一体……？僕、山登りに来ていたはずなんですが……。",
		// 	.standing_picture = TextureAsset(U"Takeshi"),
		// },
		//
		// MessageContentStruct{
		// 	.name = U"ワタシ",
		// 	.messages = U"ようこそ、ここは写真館《黄泉の前》です。",
		// 	.standing_picture = TextureAsset(U"Me"),
		// },
		//
		// MessageContentStruct{
		// 	.name = U"タケシ",
		// 	.messages = U"黄泉の前！？写真館！？",
		// 	.standing_picture = TextureAsset(U"Takeshi"),
		// },
		//
		// MessageContentStruct{
		// 	.name = U"ワタシ",
		// 	.messages = U"簡単に言うと、あなたは今ひん死状態なんです。\nここは、ひん死の人が来る場所なので。",
		// 	.standing_picture = TextureAsset(U"Me"),
		// },
		//
		// MessageContentStruct{
		// 	.name = U"タケシ",
		// 	.messages = U"おおー、だから《黄泉の前》なんですね！意味分かんないです！",
		// 	.standing_picture = TextureAsset(U"Takeshi"),
		// },

		MessageContentStruct{
			.name = U"ワタシ",
			.messages = U"確かに、意味を考え出すとアレかもしれませんが……。",
			.standing_picture = TextureAsset(U"Me"),
		}
	);

	message_window_container_ -> debug_print();

}

void PrologueScene::update()
{
	// Print << Scene::DeltaTime();
	// draw background
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);


	if(KeySpace.down()) message_window_container_->go_to_next_message();

	message_window_container_->update_logic();
	message_window_container_->update_render();


	// Cause Determination Part
	message_window_container_->update_logic();
	message_window_container_->update_render();
}

void PrologueScene::draw() const
{
}
