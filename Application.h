#include "constant.h"
#include "SceneManager.h"

#pragma once
class Application
{
public :
	Application();
	~Application();

private :
	void Init();
	void Update();
	void Draw();
};

extern Application* meApp;
