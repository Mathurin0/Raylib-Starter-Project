#include "application.h"
#include <iostream>

Application::Application() {
	Init();
}
Application::~Application() {
}

void Application::Init() {
	InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Casse Brique");
	SetTargetFPS(FPS_LIMIT);

	 mSceneManager = new SceneManager();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}

	CloseWindow();
}

void Application::Update() {
	float deltatime = GetFrameTime();
	mSceneManager->Update(deltatime);
}

void Application::Draw() {
	BeginDrawing();

	ClearBackground(BACKGROUND_COLOR);

	mSceneManager->Draw();

	EndDrawing();
}