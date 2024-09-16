#include "Application.h"
#include <iostream>

Application::Application() {
	Init();
}
Application::~Application() {
}

void Application::Init() {
	InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Casse Brique");
	SetTargetFPS(FPS_LIMIT);

	meSceneManager = new SceneManager();

	while (!WindowShouldClose()) {
		Update();
		Draw();
	}

	CloseWindow();
}

void SceneManager::Init() {
	ChangeScene(Game);
}

void Application::Update() {
	float deltatime = GetFrameTime();
	meSceneManager->Update(deltatime);
}

void Application::Draw() {
	BeginDrawing();

	ClearBackground(BACKGROUND_COLOR);

	meSceneManager->Draw();

	EndDrawing();
}