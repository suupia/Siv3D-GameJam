#pragma once

class GameObject
{
public:
	virtual void update_logic() = 0;
	virtual void update_render() const = 0;
};
