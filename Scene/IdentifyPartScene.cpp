﻿#include "../stdafx.h"
#include "IdentifyPartScene.h"
#include "../Utility/RectFUtility.h"

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
			const auto button = Button( RectFUtility::calc_relative_rect(res_x,res_y,w/2,h), font, U"{}"_fmt(index));
			const auto sticky_note = RectFUtility::calc_relative_rect(res_x+ w/2,res_y,w/2,h);
			return {button, sticky_note, false};
		}else
		{
			// odd -> left : text, right : texture
			const auto res_x = x + col_index * w;
			const auto res_y = y + row_index * h;
			const auto button = Button( RectFUtility::calc_relative_rect(res_x+ w/2,res_y,w/2,h), font, U"{}"_fmt(index));
			const auto sticky_note = RectFUtility::calc_relative_rect(res_x,res_y,w/2,h);
			return {button, sticky_note, false};
		}


	}
}

IdentifyPartScene::IdentifyPartScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48}
{
	TextureAsset::Register(U"Book", U"images/book_tmp.png") ;
	TextureAsset::Register(U"StickyNote", U"images/sticky_note_tmp.png") ;

	// ratio
	double x = 0.03;
	double y = 0.03;
	double w = 0.43;
	double h = 0.31;
	// const auto button0 = Button( RectFUtility::calc_relative_rect(x,y,w,h), font_, U"0");
	// const auto button1 = Button( RectFUtility::calc_relative_rect(x+w,y+h,w,h), font_, U"1");
	// const auto button2 = Button( RectFUtility::calc_relative_rect(x,y+2*h,w,h), font_, U"2");
	// const auto button3 = Button( RectFUtility::calc_relative_rect(x+2*w,y,w,h), font_, U"3");
	// const auto button4 = Button( RectFUtility::calc_relative_rect(x+3*w,y+h,w,h), font_, U"4");
	// const auto button5 = Button( RectFUtility::calc_relative_rect(x+2*w,y+2*h,w,h), font_, U"5");
	// const auto sticky_note0 = RectFUtility::calc_relative_rect(x+w,y,w,h);
	// const auto sticky_note1 = RectFUtility::calc_relative_rect(x+2*w,y+h,w,h);
	// const auto sticky_note2 = RectFUtility::calc_relative_rect(x+w,y+2*h,w,h);
	// const auto sticky_note3 = RectFUtility::calc_relative_rect(x,y+h,w,h);
	// const auto sticky_note4 = RectFUtility::calc_relative_rect(x+3*w,y,w,h);
	// const auto sticky_note5 = RectFUtility::calc_relative_rect(x+2*w,y+2*h,w,h);
	//
	//
	// identify_photo_data_.push_back({button0, sticky_note0, false});
	// identify_photo_data_.push_back({button1, sticky_note1, false});
	// identify_photo_data_.push_back({button2, sticky_note2, false});
	// identify_photo_data_.push_back({button3, sticky_note3, false});
	// identify_photo_data_.push_back({button4, sticky_note4, false});
	// identify_photo_data_.push_back({button5, sticky_note5, false});

	constexpr int photo_number = 6;
	for(int i = 0; i < photo_number; i++)
	{
		identify_photo_data_.push_back( create_identify_photo_data(i, x, y, w, h, font_));
	}
}

void IdentifyPartScene:: update()
{
	for(int i = 0; i< identify_photo_data_.size(); i++)
	{
		if(identify_photo_data_.at(i).button.is_down())
		{
			Print << U"button" << i << U" is down";
			identify_photo_data_.at(i).is_selected = !identify_photo_data_.at(i).is_selected;
		}
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
	(void)TextureAsset(U"Book").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	for (int i = 0; i < identify_photo_data_.size(); i++)
	{
		identify_photo_data_.at(i).button.draw();
		if (identify_photo_data_.at(i).is_selected)
		{
			auto sticky_note_pos = identify_photo_data_.at(i).sticky_note_pos;
			(void)TextureAsset(U"StickyNote").resized(sticky_note_pos.w, sticky_note_pos.h).draw(sticky_note_pos.x, sticky_note_pos.y);
		}
	}

}
