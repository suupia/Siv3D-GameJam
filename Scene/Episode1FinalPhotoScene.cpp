#include "../stdafx.h"
#include "Episode1FinalPhotoScene.h"
#include "../Utility/RectFUtility.h"
#include "../Utility/OneLineTextReader.h"

// public
Episode1FinalPhotoScene::Episode1FinalPhotoScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	next_page_button_(  RectFUtility::calc_relative_rect(0.88, 0.5, 0.1,0.08), font_, U"次のページ"),
	back_page_button_( RectFUtility::calc_relative_rect(0.02, 0.5, 0.1,0.08), font_, U"前のページ")

{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;

	const double w_margin = 0.15;
	const double h_margin = 0.05;
	const double w_ratio = (1 - 2 * w_margin);
	const double h_ratio = 0.7;

	for(int i = 0; i< final_photo_number_; i++)
	{
		const auto path = U"images/final_photo_tmp_{}.png"_fmt(i);
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
	for(auto final_photo : final_photo_buttons_)
	{
		final_photo.draw();
	}

	// draw next & back button
	next_page_button_.draw();
	back_page_button_.draw();

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
}

void Episode1FinalPhotoScene::turn_page(const bool is_next)
{
	// const auto all_page_number = identify_photo_data_.size() / all_photo_number_ + 1;
	// if (is_next)
	// {
	// 	if (current_page_ + 1 < all_page_number)
	// 		current_page_++;
	// }
	// else
	// {
	// 	if (0 <= current_page_ - 1)
	// 		current_page_--;
	// }
	// Print << U"current_page_ = " << current_page_;
}
