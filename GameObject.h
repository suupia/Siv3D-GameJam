#pragma once

class GameObject
{
public:
	virtual void update_logic() = 0;
	virtual void update_render() = 0;
};
