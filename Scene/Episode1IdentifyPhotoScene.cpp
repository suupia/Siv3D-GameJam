#include "../stdafx.h"
#include "Episode1IdentifyPhotoScene.h"
#include "../Utility/RectFUtility.h"
#include "../Utility/OneLineTextReader.h"

namespace
{
	bool is_left_page(const int col_index)
	{
		if(col_index == 0)
		{
			return true;
		}else if(col_index == 1)
		{
			return false;
		}else
		{
			throw Error(U"col_index is invalid");
		}
	}

	IdentifyPhotoData create_identify_photo_data(int index, double w_margin, double h_margin, double w, double h,Array<String> captions, const Font& font_,const int photo_number_per_row, const int photo_number_per_page)
	{
		const int photo_index = index % photo_number_per_page;  // Indicates the position of the photo on the page.
		const int row_index = photo_index % photo_number_per_row;
		const int col_index = photo_index / photo_number_per_row ;

		String caption = captions.at(index);
		// Print << U"caption = " << caption;

		// calculate the position of the photo
		const auto x = w_margin + col_index * w;
		const auto y  = h_margin + row_index * h;

		// calculate the position of the sticky note
		double sticky_w = w/3;
		double sticky_h = h/4;
		double sticky_x =  is_left_page(col_index)? w_margin - 60/100.0 * w_margin : x + w - sticky_w + 60/100.0* w_margin;
		double sticky_y = y + h/3;
		const auto sticky_pos = RectFUtility::calc_relative_rect(sticky_x,sticky_y,sticky_w,sticky_h);

		auto rand_angle =  Random(-12_deg, 12_deg);

		if(photo_index % 2 == 0)
		{
			// even -> left : texture, right : text
			const auto button = Button( RectFUtility::calc_relative_rect(x,y,w/2,h), rand_angle,U"IdentifyPhoto{}"_fmt(index));
			const auto caption_pos = RectFUtility::calc_relative_rect(x+ w/2,y,w/2,h);
			return {button, sticky_pos,  captions.at(index),caption_pos, false};
		}else
		{
			// odd -> left : text, right : texture
			const auto button = Button( RectFUtility::calc_relative_rect(x+ w/2,y,w/2,h), rand_angle,U"IdentifyPhoto{}"_fmt(index));
			const auto caption_pos = RectFUtility::calc_relative_rect(x,y,w/2,h);
			return {button, sticky_pos,  captions.at(index),caption_pos,false};
		}

	}

	struct RingEffect : IEffect
	{
		Vec2 m_pos;
		ColorF m_color;

		// このコンストラクタ引数が、Effect::add<RingEffect>() の引数になる
		explicit RingEffect(const Vec2& pos, ColorF color)
			: m_pos{ pos }
		, m_color{color } {}

		bool update(double t) override
		{
			// イージング
			const double e = EaseOutExpo(t);

			Circle{ m_pos, (e * 150) }.drawFrame((10.0 * (1.0 - e)), m_color);

			return (t < 1.0);
		}
	};

}

// public
Episode1IdentifyPhotoScene::Episode1IdentifyPhotoScene(const InitData& init):
	IScene(init),
	gm_(GameManager()),
	font_{FontMethod::MSDF, 48, U"fonts/ZenAntiqueSoft.ttf" },
	next_page_button_(  RectFUtility::calc_relative_rect(0.85, 0.9, 0.1,0.08), font_, U"次のページ"),
	back_page_button_( RectFUtility::calc_relative_rect(0.05, 0.9, 0.1,0.08), font_, U"前のページ"),
	confirm_button_(RectFUtility::calc_relative_rect(0.45, 0.9, 0.1,0.08), font_, U"確定"),
	identify_photo_calculator_({0,2,3,5,7,10})
{
	TextureAsset::Register(U"Book", U"images/album.png") ;
	TextureAsset::Register(U"StickyNote", U"images/sticky_note_tmp.png") ;
	for(int i = 0; i< all_photo_number_; i++)
	{
		const auto path = U"images/identify_photo_{}.png"_fmt(i);
		TextureAsset::Register(U"IdentifyPhoto{}"_fmt(i), path) ;
	}

	const double w_margin = 0.05;
	const double h_up_margin = 0.08;
	const double h_down_margin = 0.15;
	const double w_ratio = (1 - 2 * w_margin)  / photo_number_per_col_;
	const double h_ratio = (1 - (h_up_margin + h_down_margin))  / photo_number_per_row_;


	OneLineTextReader reader(U"texts/takeshi_identify_texts.txt");
	const auto captions = reader.readOneLineAll();

	for(int i = 0; i < all_photo_number_; i++)
	{
		identify_photo_data_.push_back( create_identify_photo_data(i, w_margin, h_up_margin, w_ratio, h_ratio,captions, font_, photo_number_per_row_, photo_number_per_page_));
	}

	effects_.resize(all_page_number());

}

void Episode1IdentifyPhotoScene:: update()
{
	detect_button();

	// debug is_selected_array
	if (KeyD.down())
	{
		for (int i = 0; i < identify_photo_data_.size(); i++)
		{
			// Print << U"is_selected_array[" << i << U"] = " << identify_photo_data_.at(i).is_selected;
		}
	}
}

void Episode1IdentifyPhotoScene:: draw() const
{
	// draw background
	(void)TextureAsset(U"Book").resized(Scene::Width(),Scene::Height()).draw(0, 0);

	// draw identify photos
	const auto start_index = current_page_ * photo_number_per_page_;
	const auto end_index = start_index + photo_number_per_page_;
	for (int i = start_index; i < end_index; i++)
	{
		identify_photo_data_.at(i).button.draw();

		auto caption = identify_photo_data_.at(i).caption_text;
		const auto caption_rect = identify_photo_data_.at(i).caption_rect;
		(void)font_(caption).drawAt(30, caption_rect.x + caption_rect.w / 2 , caption_rect.y + caption_rect.h / 2, Palette::Black);
		if (identify_photo_data_.at(i).is_selected)
		{
			const auto sticky_note_pos = identify_photo_data_.at(i).sticky_note_pos;
			(void)TextureAsset(U"StickyNote").resized(sticky_note_pos.w, sticky_note_pos.h).draw(sticky_note_pos.x, sticky_note_pos.y);
		}

	}

	// draw next & back button
	next_page_button_.draw();
	back_page_button_.draw();
	confirm_button_.draw();

	// update effects
	effects_.at(current_page_).update();

}

// private

/// <summary>
/// In this method, we detect is_down() on buttons and then "return" to avoid duplicate detection.
/// </summary>
void Episode1IdentifyPhotoScene::detect_button()
{
	// detect is_down() on next & back button
	if(next_page_button_.is_down())
	{
		// Print << U"next page button is down";
		turn_page(true);
		return;
	}
	if(back_page_button_.is_down())
	{
		// Print << U"back page button is down";
		turn_page(false);
		return;
	}
	if(confirm_button_.is_down())
	{
		// Print << U"confirm button is down";
		const auto wrong_selected_photos = identify_photo_calculator_.calc_wrong_selected_photos(identify_photo_data_);
		const auto not_selected_photos = identify_photo_calculator_.not_selected_photos(identify_photo_data_);
		for(int i = 0; i< wrong_selected_photos.size(); i++)
		{
			// Print << U"wrong_selected_photos[" << i << U"] = " << wrong_selected_photos.at(i);
		}
		for(int i = 0; i< not_selected_photos.size(); i++)
		{
			// Print << U"not_selected_photos[" << i << U"] = " << not_selected_photos.at(i);
		}
		if (wrong_selected_photos.empty() && not_selected_photos.empty())
		{
			changeScene(SceneState::Episode1Answer, 2.0s);
		}
		else
		{
			for(int page_index = 0 ; page_index < all_page_number() ; page_index ++)
			{
				effects_.at(page_index).clear();
				const auto start_index = page_index * photo_number_per_page_;
				const auto end_index = start_index + photo_number_per_page_;
				for(const auto wrong_selected_index : wrong_selected_photos)
				{
					if( start_index<= wrong_selected_index && wrong_selected_index < end_index)
					{
						const auto button = identify_photo_data_.at(wrong_selected_index).button;
						effects_.at(page_index).add<RingEffect>(button.get_rect().center(), Palette::Red);
					}
				}
				for(const auto not_selected_index : not_selected_photos)
				{
					if( start_index<= not_selected_index && not_selected_index < end_index)
					{
						const auto button = identify_photo_data_.at(not_selected_index).button;
						effects_.at(page_index).add<RingEffect>(button.get_rect().center(), Palette::Green);
					}
				}
			}

		}
		return;
	}

	// detect is_down() on identify photos
	const auto start_index = current_page_ * photo_number_per_page_;
	const auto end_index = start_index + photo_number_per_page_;
	for(int i = start_index; i< end_index; i++)
	{
		if(identify_photo_data_.at(i).button.is_down())
		{
			// Print << U"button" << i << U" is down";
			identify_photo_data_.at(i).is_selected = !identify_photo_data_.at(i).is_selected;
			return;
		}
	}
}

void Episode1IdentifyPhotoScene::turn_page(const bool is_next)
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
	// Print << U"current_page_ = " << current_page_;
}


