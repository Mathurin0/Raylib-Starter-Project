#pragma once
#include "scene.h"
#include "constant.h"
#include "sceneManager.h"

class Win : public Scene
{
public:
	Win();
	~Win();

	void Init() override;
	void Update(float deltaTime) override;
	void Draw() override;

private:
	Rectangle mRestartButton;
	Rectangle mMenuButton;
};

