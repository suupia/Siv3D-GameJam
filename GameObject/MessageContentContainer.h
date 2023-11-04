#pragma once
#include "../GameManager/GameManager.h"
#include "GameObject.h"
#include "MessageContent.h"
#include "../Utility/RectFUtility.h"

struct NextPageEffect : IEffect
{
	Vec2 m_pos;

	ColorF m_color;

	explicit NextPageEffect(const Vec2& pos)
		: m_pos{ pos }
	, m_color{ RandomColorF() } {}

	bool update(double t) override
	{
		// イージング
		auto mod_t =t;
		int cycle_t = 2;
		while(mod_t > cycle_t)
		{
			mod_t -= cycle_t;
		}
		Print << U"mod_t: " << mod_t << U" cycle_t: " << cycle_t << U" t: " << t;

		const double e = EaseOutExpo(mod_t);

		Circle{ m_pos, (e * 100) }.drawFrame((20.0 * (1.0 - e)), m_color);


		return  true;
	}
};

class MessageContentContainer : public GameObject
{
public:
	MessageContentContainer(GameManager& gm, const Font& font
		) : gm_(gm), font_(font)
	{
		logic_id_ = gm_.register_logic([&]() { this->update_logic();});
		render_id_ = gm_.register_render([&]() { this->update_render();});

	   const auto rect = RectFUtility::calc_relative_rect(0, 0, 0.9, 0.9);
		next_page_effect_.add<NextPageEffect>(Vec2{rect.w, rect.h});
	}

	~MessageContentContainer()
	{
		gm_.unregister_logic(logic_id_);
		gm_.unregister_render(render_id_);
	}

	void update_logic() override;
	void update_render() const override;

	void add_message_contents(const Array<MessageContent>& message_content_structs);
	void go_to_next_message();
	bool is_message_finished() const ;
private:
	GameManager& gm_;
	int logic_id_;
	int render_id_;
	const Font& font_;

	Effect next_page_effect_;

	Array<MessageContent> message_contents_;
	int current_message_content_index_ = 0;


};
