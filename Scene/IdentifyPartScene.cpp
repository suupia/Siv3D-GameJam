#include "../stdafx.h"
#include "IdentifyPartScene.h"
#include "../Utility/RectFUtility.h"
#include "../Utility/OneLineTextReader.h"

namespace
{
	IdentifyPhotoData create_identify_photo_data(int index, double x, double y, double w, double h, const Font& font)
	{
		constexpr int row_number = 3;
		constexpr int col_number = 2;

		const int row_index = index % 3;
		const int col_index = index / 3;
		const int page_index = index / (row_number * col_number);

		if(index % 2 == 0)
		{
			// even -> left : texture, right : text
			const auto res_x = x + col_index * w;
			const auto res_y = y + row_index * h;
			const auto button = Button( RectFUtility::calc_relative_rect(res_x,res_y,w/2,h), font, U"{}"_fmt(index),U"IdentifyPhoto{}"_fmt(index));
			const auto sticky_note = RectFUtility::calc_relative_rect(res_x+ w/2,res_y,w/2,h);
			return {button, sticky_note, false};
		}else
		{
			// odd -> left : text, right : texture
			const auto res_x = x + col_index * w;
			const auto res_y = y + row_index * h;
			const auto button = Button( RectFUtility::calc_relative_rect(res_x+ w/2,res_y,w/2,h), font, U"{}"_fmt(index),U"IdentifyPhoto{}"_fmt(index));
			const auto sticky_note = RectFUtility::calc_relative_rect(res_x,res_y,w/2,h);
			return {button, sticky_note, false};
		}


	}
}

IdentifyPartScene::IdentifyPartScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	next_page_button_(  RectFUtility::calc_relative_rect(0.05, 0.8, 0.1,0.08), font_, U"次のページ"),
	back_page_button_( RectFUtility::calc_relative_rect(0.85, 0.8, 0.1,0.08), font_, U"前のページ")
{
	constexpr int photo_number = 6;
	TextureAsset::Register(U"Book", U"images/book_tmp.png") ;
	TextureAsset::Register(U"StickyNote", U"images/sticky_note_tmp.png") ;
	for(int i = 0; i< photo_number; i++)
	{
		const auto path = U"images/identify_photo_tmp_{}.png"_fmt(i);
		TextureAsset::Register(U"IdentifyPhoto{}"_fmt(i), path) ;
	}

	// ratio
	double x = 0.03;
	double y = 0.03;
	double w = 0.43;
	double h = 0.31;

	for(int i = 0; i < photo_number; i++)
	{
		identify_photo_data_.push_back( create_identify_photo_data(i, x, y, w, h, font_));
	}

	// debug
	OneLineTextReader reader(U"texts/takeshi_identify_texts.txt");
	const auto array = reader.readOneLineAll();
	for(auto text : array)
	{
		Print << text;
	}

}

void IdentifyPartScene:: update()
{
	// detect is_down() on identify photos
	for(int i = 0; i< identify_photo_data_.size(); i++)
	{
		if(identify_photo_data_.at(i).button.is_down())
		{
			Print << U"button" << i << U" is down";
			identify_photo_data_.at(i).is_selected = !identify_photo_data_.at(i).is_selected;
		}
	}

	// detect is_down() on next & back button
	if(next_page_button_.is_down())
	{
		Print << U"next page button is down";
	}
	if(back_page_button_.is_down())
	{
		Print << U"back page button is down";
	}

	// debug is_selected_array
	if (KeyD.down())
	{
		for (int i = 0; i < identify_photo_data_.size(); i++)
		{
			Print << U"is_selected_array[" << i << U"] = " << identify_photo_data_.at(i).is_selected;
		}
	}
}

void IdentifyPartScene:: draw() const
{
	// draw background
	(void)TextureAsset(U"Book").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	// draw identify photos
	for (int i = 0; i < identify_photo_data_.size(); i++)
	{
		identify_photo_data_.at(i).button.draw();
		if (identify_photo_data_.at(i).is_selected)
		{
			const auto sticky_note_pos = identify_photo_data_.at(i).sticky_note_pos;
			(void)TextureAsset(U"StickyNote").resized(sticky_note_pos.w, sticky_note_pos.h).draw(sticky_note_pos.x, sticky_note_pos.y);
		}
	}

	// draw next & back button
	next_page_button_.draw();
	back_page_button_.draw();

}
