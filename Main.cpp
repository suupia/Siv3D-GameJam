﻿# include <Siv3D.hpp> // OpenSiv3D v0.6.11

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

RectF get_relative_rect(double offset_x, double offset_y, double width, double height)
{
	return RectF{ offset_x * Scene::Width(), offset_y * Scene::Height(), width * Scene::Width(), height * Scene::Height() };
}

void open_message_window()
{
	// message box
	get_relative_rect(0, 3.0/5.0, 1, 2.0/5.0).draw(Palette::Lightslategray);

	// name box
	get_relative_rect(1.0/10.0,4.0/10.0,1.0/2.0,2.0/5.0).draw(Palette::Teal);

}

void Main()
{

	set_up_window();
	while (System::Update())
	{
		open_message_window();
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
