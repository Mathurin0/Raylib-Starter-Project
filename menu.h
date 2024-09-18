#pragma once
#include "scene.h"
#include "constant.h"
#include "sceneManager.h"

class Menu : public Scene
{
public:
	Menu();
	~Menu();

	void Init() override;
	void Update(float deltaTime) override;
	void Draw() override;

private:
	Rectangle mStartButton;
};
