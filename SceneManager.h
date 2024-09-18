#pragma once
#ifndef SCENE_MANAGER
#define SCENE_MANAGER
#include "scene.h"
#include "game.h"
#include "lose.h"
#include "menu.h"
#include "win.h"

enum Scenes {
	MenuScene,
	GameScene,
	WinScene,
	LoseScene
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Update(float deltaTime);
	void Draw();

	void ChangeScene(Scenes sceneToOpen);

private:
	Scene* mCurrentScene;
	void Init();
};

extern SceneManager* mSceneManager;
#endif