#pragma once
#include "scene.h"
#include "game.h"

enum Scenes {
	GameScene
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Update(float deltaTime);
	void Draw();

	void ChangeScene(Scenes sceneToOpen);
	void LoadScene(int index);

private:
	Scene* mCurrentScene;
	void Init();
};