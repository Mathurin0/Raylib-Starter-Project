#pragma once
#include "scene.h"
#include "constant.h"
#include "sceneManager.h"

class Lose : public Scene
{
public:
	Lose();
	~Lose();

	void Init() override;
	void Update(float deltaTime) override;
	void Draw() override;

private :
	Rectangle mRestartButton;
	Rectangle mMenuButton;
};