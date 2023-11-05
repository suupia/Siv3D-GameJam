# include <Siv3D.hpp> // OpenSiv3D v0.6.11

#include "Scene/Episode1AnswerScene.h"
#include "Scene/Episode1FinalPhotoScene.h"
#include "Scene/Episode1MultiEndScene.h"
#include "Scene/SceneSetting.h"
#include "Scene/Episode1Scene.h"
#include "Scene/Episode1IdentifyPhotoScene.h"
#include "Scene/PrologueScene.h"
#include "Scene/TitleScene.h"

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
		scene_manager.add<Episode1Scene>(SceneState::Episode1);
		scene_manager.add<Episode1IdentifyPhotoScene>(SceneState::Episode1IdentifyPhoto);
		scene_manager.add<Episode1AnswerScene>(SceneState::Episode1Answer);
		scene_manager.add<Episode1FinalPhotoScene>(SceneState::Episode1FinalPhoto);
		scene_manager.add<Episode1MultiEndScene>(SceneState::Episode1MultiEnd);

		scene_manager.init(SceneState::Title);
		return  scene_manager;
	}
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

		if(not scene_manager.update()) break;

		// for debug
		if(Key1.pressed())
		{
			scene_manager.changeScene(SceneState::Title);
		}
		if(Key2.pressed())
		{
			scene_manager.changeScene(SceneState::Prologue);
		}
		if(Key3.pressed())
		{
			scene_manager.changeScene(SceneState::Episode1);
		}
		if(Key4.pressed())
		{
			scene_manager.changeScene(SceneState::Episode1IdentifyPhoto);
		}
		if(Key5.pressed())
		{
			scene_manager.changeScene(SceneState::Episode1Answer);
		}
		if(Key6.pressed())
		{
			scene_manager.changeScene(SceneState::Episode1FinalPhoto);
		}
		if(Key7.pressed())
		{
			scene_manager.changeScene(SceneState::Episode1MultiEnd);
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
