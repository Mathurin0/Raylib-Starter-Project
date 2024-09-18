#include "menu.h"
#include <iostream>

Menu::Menu() {
	Init();
}

Menu::~Menu() {

}

void Menu::Init() {
	mStartButton.x = 760;
	mStartButton.y = 500;
	mStartButton.width = 400;
	mStartButton.height = 100;
}

void Menu::Update(float deltaTime) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (GetMousePosition().x > mStartButton.x && GetMousePosition().x < mStartButton.x + mStartButton.width && GetMousePosition().y > mStartButton.y && GetMousePosition().y < mStartButton.y + mStartButton.height) {
			mSceneManager->ChangeScene(GameScene);
		}
	}
}

void Menu::Draw() {
	DrawText(TextFormat("BRICK BREACKER"), 790, 300, 40, WHITE);
	DrawRectangle(mStartButton.x, mStartButton.y, mStartButton.width, mStartButton.height, WHITE);
	DrawText(TextFormat("Start"), mStartButton.x + 140, mStartButton.y + 35, 30, BLACK);
}