#pragma once
#include <Siv3D.hpp>

enum class SceneState {
	Title,
	Prologue,
	Episode1,
	Episode2,
	Episode3,
	IdentifyProcess,
	SelectPhotoProcess,
	Epilogue,
};

struct SceneData {
	
};

using Scene = SceneManager<SceneState, SceneData>;
