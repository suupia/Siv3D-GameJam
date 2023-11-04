#pragma once
#include <Siv3D.hpp>

enum class SceneState {
	Title,
	Prologue,
	Episode1,
	Episode1IdentifyPhoto,
	Episode1Answer,
	Episode1FinalPhoto,
	Episode1MultiEnd,
	Episode2,
	Episode3,
	Epilogue,
};

struct SceneData {
	int32 chosen_final_photo_index;
};
