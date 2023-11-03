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

	buttons_.push_back(button0);
	buttons_.push_back(button1);
	buttons_.push_back(button2);
	buttons_.push_back(button3);
	buttons_.push_back(button4);
	buttons_.push_back(button5);

	sticky_note_poss_.push_back(sticky_note0);
	sticky_note_poss_.push_back(sticky_note1);
	sticky_note_poss_.push_back(sticky_note2);
	sticky_note_poss_.push_back(sticky_note3);
	sticky_note_poss_.push_back(sticky_note4);
	sticky_note_poss_.push_back(sticky_note5);

	is_selected_array.resize(buttons_.size());
}

void IdentifyPartScene:: update()
{
	for(int i = 0; i< buttons_.size(); i++)
	{
		if(buttons_[i].is_down())
		{
			Print << U"button" << i << U" is down";
			is_selected_array[i] = !is_selected_array[i];
		}
	}

	// debug is_selected_array
	if (KeyD.down())
	{
		for (int i = 0; i < is_selected_array.size(); i++)
		{
			Print << U"is_selected_array[" << i << U"] = " << is_selected_array[i];
		}
	}
}

void IdentifyPartScene:: draw() const
{
	(void)TextureAsset(U"Book").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	for(const auto& button : buttons_)
	{
		button.draw();
	}

	for(int i = 0; i< sticky_note_poss_.size(); i++)
	{
		if(is_selected_array.at(i))

		(void)TextureAsset(U"StickyNote").resized(sticky_note_poss_[i].w,sticky_note_poss_[i].h).draw(sticky_note_poss_[i].x, sticky_note_poss_[i].y);
	}

}
