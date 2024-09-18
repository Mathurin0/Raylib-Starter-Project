#include "sceneManager.h"

SceneManager* mSceneManager = nullptr;

SceneManager::SceneManager() {
	Init();
}

SceneManager::~SceneManager() {

}

void SceneManager::Init() {
	mCurrentScene = nullptr;
	ChangeScene(MenuScene);
}

void SceneManager::Update(float deltaTime) {
	mCurrentScene->Update(deltaTime);
}

void SceneManager::Draw() {
	mCurrentScene->Draw();
}

void SceneManager::ChangeScene(Scenes scene) {
	if (mCurrentScene != nullptr) {
		mCurrentScene->~Scene();
	}

	switch (scene)
	{
		case MenuScene:
			mCurrentScene = new Menu();
			break;

		case GameScene:
			mCurrentScene = new Game();
			break;

		case LoseScene:
			mCurrentScene = new Lose();
			break;

		case WinScene:
			mCurrentScene = new Win();
			break;
	}
}