#include "../stdafx.h"
#include "IdentifyPartScene.h"
#include "../Utility/RectFUtility.h"

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
	double w = 0.23;
	double h = 0.31;
	const auto button0 = Button( RectFUtility::calc_relative_rect(x,y,w,h), font_, U"0");
	const auto button1 = Button( RectFUtility::calc_relative_rect(x+w,y+h,w,h), font_, U"1");
	const auto button2 = Button( RectFUtility::calc_relative_rect(x,y+2*h,w,h), font_, U"2");
	const auto button3 = Button( RectFUtility::calc_relative_rect(x+2*w,y,w,h), font_, U"3");
	const auto button4 = Button( RectFUtility::calc_relative_rect(x+3*w,y+h,w,h), font_, U"4");
	const auto button5 = Button( RectFUtility::calc_relative_rect(x+2*w,y+2*h,w,h), font_, U"5");
	const auto sticky_note0 = RectFUtility::calc_relative_rect(x+w,y,w,h);
	const auto sticky_note1 = RectFUtility::calc_relative_rect(x+2*w,y+h,w,h);
	const auto sticky_note2 = RectFUtility::calc_relative_rect(x+w,y+2*h,w,h);
	const auto sticky_note3 = RectFUtility::calc_relative_rect(x,y+h,w,h);
	const auto sticky_note4 = RectFUtility::calc_relative_rect(x+3*w,y,w,h);
	const auto sticky_note5 = RectFUtility::calc_relative_rect(x+2*w,y+2*h,w,h);


	identify_photo_data_.push_back({button0, sticky_note0, false});
	identify_photo_data_.push_back({button1, sticky_note1, false});
	identify_photo_data_.push_back({button2, sticky_note2, false});
	identify_photo_data_.push_back({button3, sticky_note3, false});
	identify_photo_data_.push_back({button4, sticky_note4, false});
	identify_photo_data_.push_back({button5, sticky_note5, false});
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
