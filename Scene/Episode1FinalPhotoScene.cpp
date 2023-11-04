#include "../stdafx.h"
#include "Episode1FinalPhotoScene.h"
#include "../Utility/RectFUtility.h"
#include "../Utility/OneLineTextReader.h"

// public
Episode1FinalPhotoScene::Episode1FinalPhotoScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	next_page_button_(  RectFUtility::calc_relative_rect(0.85, 0.9, 0.1,0.08), font_, U"次のページ"),
	back_page_button_( RectFUtility::calc_relative_rect(0.05, 0.9, 0.1,0.08), font_, U"前のページ")

{
	TextureAsset::Register(U"PhotoStudio", U"images/back_photoStudio.png") ;

}

void Episode1FinalPhotoScene::update(){

	detect_button();
}

void Episode1FinalPhotoScene::draw() const {
	(void)TextureAsset(U"PhotoStudio").resized(Scene::Width(),Scene::Height()).draw(0, 0);

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
