#include "../stdafx.h"
#include "IdentifyPartScene.h"
#include "../Utility/RectFUtility.h"
#include "../Utility/OneLineTextReader.h"

namespace
{
	IdentifyPhotoData create_identify_photo_data(int index, double x, double y, double w, double h,Array<String> captions, const Font& font_, const int photo_number_per_page)
	{
		const int photo_index = index % photo_number_per_page;  // Indicates the position of the photo on the page.
		const int row_index = photo_index % 3;
		const int col_index = photo_index / 3;

		String caption = captions.at(index);
		Print << U"caption = " << caption;

		if(photo_index % 2 == 0)
		{
			// even -> left : texture, right : text
			const auto res_x = x + col_index * w;
			const auto res_y = y + row_index * h;
			const auto button = Button( RectFUtility::calc_relative_rect(res_x,res_y,w/2,h), font_, U"{}"_fmt(index),U"IdentifyPhoto{}"_fmt(index));
			const auto sticky_note = RectFUtility::calc_relative_rect(res_x+ w/2,res_y,w/2,h);
			const auto caption_pos = RectFUtility::calc_relative_rect(res_x+ w/2,res_y,w/2,h);
			return {button, sticky_note,  captions.at(index),caption_pos, false};
		}else
		{
			// odd -> left : text, right : texture
			const auto res_x = x + col_index * w;
			const auto res_y = y + row_index * h;
			const auto button = Button( RectFUtility::calc_relative_rect(res_x+ w/2,res_y,w/2,h), font_, U"{}"_fmt(index),U"IdentifyPhoto{}"_fmt(index));
			const auto sticky_note = RectFUtility::calc_relative_rect(res_x,res_y,w/2,h);
			const auto caption_pos = RectFUtility::calc_relative_rect(res_x,res_y,w/2,h);
			return {button, sticky_note,  captions.at(index),caption_pos,false};
		}
	}

}

// public
IdentifyPartScene::IdentifyPartScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48},
	next_page_button_(  RectFUtility::calc_relative_rect(0.85, 0.9, 0.1,0.08), font_, U"次のページ"),
	back_page_button_( RectFUtility::calc_relative_rect(0.05, 0.9, 0.1,0.08), font_, U"前のページ"),
	confirm_button_(RectFUtility::calc_relative_rect(0.45, 0.9, 0.1,0.08), font_, U"確定")
{
	TextureAsset::Register(U"Book", U"images/book_tmp.png") ;
	TextureAsset::Register(U"StickyNote", U"images/sticky_note_tmp.png") ;
	for(int i = 0; i< all_photo_number_; i++)
	{
		const auto path = U"images/identify_photo_tmp_{}.png"_fmt(i);
		TextureAsset::Register(U"IdentifyPhoto{}"_fmt(i), path) ;
	}

	// ratio
	double x = 0.03;
	double y = 0.03;
	double w = 0.43;
	double h = 0.31;


	OneLineTextReader reader(U"texts/takeshi_identify_texts.txt");
	const auto captions = reader.readOneLineAll();

	for(int i = 0; i < all_photo_number_; i++)
	{
		identify_photo_data_.push_back( create_identify_photo_data(i, x, y, w, h,captions, font_, photo_number_per_page_));
	}

}

void IdentifyPartScene:: update()
{
	detect_button();

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
	const auto start_index = current_page_ * photo_number_per_page_;
	const auto end_index = start_index + photo_number_per_page_;
	for (int i = start_index; i < end_index; i++)
	{
		identify_photo_data_.at(i).button.draw();
		if (identify_photo_data_.at(i).is_selected)
		{
			const auto sticky_note_pos = identify_photo_data_.at(i).sticky_note_pos;
			(void)TextureAsset(U"StickyNote").resized(sticky_note_pos.w, sticky_note_pos.h).draw(sticky_note_pos.x, sticky_note_pos.y);
		}

		auto caption = identify_photo_data_.at(i).caption_text;
		const auto caption_rect = identify_photo_data_.at(i).caption_rect;
		(void)font_(caption).drawAt(30, caption_rect.x + caption_rect.w / 2 , caption_rect.y + caption_rect.h / 2, Palette::Black);

	}

	// draw next & back button
	next_page_button_.draw();
	back_page_button_.draw();
	confirm_button_.draw();

}

// private

/// <summary>
/// In this method, we detect is_down() on buttons and then "return" to avoid duplicate detection.
/// </summary>
void IdentifyPartScene::detect_button()
{
	// detect is_down() on next & back button
	if(next_page_button_.is_down())
	{
		Print << U"next page button is down";
		turn_page(true);
		return;
	}
	if(back_page_button_.is_down())
	{
		Print << U"back page button is down";
		turn_page(false);
		return;
	}
	if(confirm_button_.is_down())
	{
		Print << U"confirm button is down";
		changeScene(SceneState::Episode1Answer, 2.0s);
		return;
	}

	// detect is_down() on identify photos
	for(int i = 0; i< identify_photo_data_.size(); i++)
	{
		if(identify_photo_data_.at(i).button.is_down())
		{
			Print << U"button" << i << U" is down";
			identify_photo_data_.at(i).is_selected = !identify_photo_data_.at(i).is_selected;
			return;
		}
	}
}

void IdentifyPartScene::turn_page(const bool is_next)
{
	const auto all_page_number = identify_photo_data_.size() / all_photo_number_ + 1;
	if(is_next)
	{
		if(current_page_ + 1 < all_page_number)
		current_page_++;
	}else
	{
		if(0 <= current_page_ - 1)
		current_page_--;
	}
	Print << U"current_page_ = " << current_page_;
}


