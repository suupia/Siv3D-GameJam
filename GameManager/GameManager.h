#pragma once
class GameManager {
private:
	std::vector<std::function<void()>> logicFunctions;   // List of functions for updating game logic
	std::vector<std::function<void()>> renderFunctions;  // List of functions for rendering graphics

	public:
	int register_logic(const std::function<void()>& func);
	int register_render(const std::function<void()>& func);
	void unregister_logic(int id);
	void unregister_render(int id);
	void update_logic();
	void update_render();

};
