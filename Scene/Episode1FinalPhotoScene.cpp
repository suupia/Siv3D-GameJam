#include "../stdafx.h"
#include "Episode1FinalPhotoScene.h"
#include "../Utility/RectFUtility.h"
#include "../Utility/OneLineTextReader.h"

// public
Episode1FinalPhotoScene::Episode1FinalPhotoScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	next_page_button_(  RectFUtility::calc_relative_rect(0.88, 0.4, 0.1,0.08), font_, U"次のページ"),
	back_page_button_( RectFUtility::calc_relative_rect(0.02, 0.4, 0.1,0.08), font_, U"前のページ"),
	confirm_button_(RectFUtility::calc_relative_rect(0.45, 0.9, 0.1,0.08), font_, U"確定")

{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;

	const double w_margin = 0.25;
	const double h_margin = 0.05;
	const double w_ratio = (1 - 2 * w_margin);
	const double h_ratio = 0.6;

	OneLineTextReader reader(U"texts/final_photo_captions_tmp.txt");
	final_photo_captions_ = reader.readOneLineAll();

	for(int i = 0; i< final_photo_number_; i++)
	{
		const auto path = U"images/final_photo_{}.png"_fmt(i);
		TextureAsset::Register(U"FinalPhoto{}"_fmt(i), path) ;
		const auto button = Button( RectFUtility::calc_relative_rect(w_margin,h_margin,w_ratio,h_ratio), font_, U"{}"_fmt(i),U"FinalPhoto{}"_fmt(i));
		final_photo_buttons_.push_back(button);
	}


}

void Episode1FinalPhotoScene::update(){

	detect_button();
}

void Episode1FinalPhotoScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	// draw final photo
	final_photo_buttons_.at(current_photo_index_).draw();

	// draw description
	// back ground box
	const auto back_ground_rect = RectFUtility::calc_relative_rect(0, 3.0/5.0, 1, 2.0/5.0).draw(Palette::Lightslategray);

	// message box
	const auto message_rect= RectFUtility::to_horizontal_center( RectF{back_ground_rect.x, back_ground_rect.y, back_ground_rect.w * 0.8, back_ground_rect.h} );
	(void)message_rect.draw(Palette::Lightblue);
	font_(final_photo_captions_.at(current_photo_index_)).draw(Arg::topLeft(message_rect.x + message_rect.w * 0.1, message_rect.y + message_rect.h * 0.2), Palette::Black);  // message_rectをそのまま使って場所を決めているわけではないことに注意


	// draw next & back button
	next_page_button_.draw();
	back_page_button_.draw();
	confirm_button_.draw();

}

/// <summary>
/// In this method, we detect is_down() on buttons and then "return" to avoid duplicate detection.
/// </summary>
void Episode1FinalPhotoScene::detect_button()
{
	// detect is_down() on next & back button
	if (next_page_button_.is_down())
	{
		Print << U"next page button is down";
		turn_page(true);
		return;
	}
	if (back_page_button_.is_down())
	{
		Print << U"back page button is down";
		turn_page(false);
		return;
	}
	if(confirm_button_.is_down())
	{
		Print << U"confirm button is down";
		return;
	}

}

void Episode1FinalPhotoScene::turn_page(const bool is_next)
{
	if (is_next)
	{
		if (current_photo_index_ + 1 < final_photo_number_)
			current_photo_index_++;
	}
	else
	{
		if (0 <= current_photo_index_ - 1)
			current_photo_index_--;
	}
	Print << U"current_photo_index_ = " << current_photo_index_;
}
