#include "sceneManager.h"

SceneManager* sceneManager = nullptr;

SceneManager::SceneManager() {
	Init();
}

SceneManager::~SceneManager() {

}

void SceneManager::Init() {
	mCurrentScene = nullptr;
	ChangeScene(GameScene);
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
		case GameScene:
			mCurrentScene = new Game();
			break;
	}
}