#pragma once
#include "scene.h"

enum Scenes {
	Game
};

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	void Update(float deltaTime);
	void Draw();

	void ChangeScene();
	void LoadScene();

private:
	Scene* mCurrentScene;
	void Init();
};

extern SceneManager* meSceneManager;