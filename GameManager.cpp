#include "stdafx.h"
#include "GameManager.h"

// コールバックの登録時にユニークなIDを返す
int GameManager::register_logic(const std::function<void()>& func) {
	logicFunctions.emplace_back(func);
	return logicFunctions.size() - 1; // IDはインデックスとする
}

int GameManager::register_render(const std::function<void()>& func) {
	renderFunctions.emplace_back(func);
	return renderFunctions.size() - 1; // IDはインデックスとする
}

// IDを使用して、特定のコールバックを削除する
void GameManager::unregister_logic(int id) {
	logicFunctions[id] = nullptr; // 関数を無効にする
}

void GameManager::unregister_render(int id) {
	renderFunctions[id] = nullptr; // 関数を無効にする
}

void GameManager::update_logic() {
	for (const auto& func : logicFunctions) {
		if (func) {
			func();
		}
	}
}

void GameManager::update_render() {
	for (const auto& func : renderFunctions) {
		if (func) {
			func();
		}
	}
}
