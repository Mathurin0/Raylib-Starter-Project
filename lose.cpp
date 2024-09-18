#include "lose.h"
#include <iostream>

Lose::Lose() {
	Init();
}

Lose::~Lose() {

}

void Lose::Init() {
	mRestartButton.x = 510;
	mRestartButton.y = 500;
	mRestartButton.width = 400;
	mRestartButton.height = 100;

	mMenuButton.x = 1010;
	mMenuButton.y = 500;
	mMenuButton.width = 400;
	mMenuButton.height = 100;
}

void Lose::Update(float deltaTime) {
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		if (GetMousePosition().x > mRestartButton.x && GetMousePosition().x < mRestartButton.x + mRestartButton.width && GetMousePosition().y > mRestartButton.y && GetMousePosition().y < mRestartButton.y + mRestartButton.height) {
			mSceneManager->ChangeScene(GameScene);
		}
		else if (GetMousePosition().x > mMenuButton.x && GetMousePosition().x < mMenuButton.x + mMenuButton.width && GetMousePosition().y > mMenuButton.y && GetMousePosition().y < mMenuButton.y + mMenuButton.height) {
				mSceneManager->ChangeScene(MenuScene);
		}
	}
}

void Lose::Draw() {
	DrawText(TextFormat("YOU LOSE..."), 850, 300, 40, RED);
	DrawRectangle(mRestartButton.x, mRestartButton.y, mRestartButton.width, mRestartButton.height, WHITE);
	DrawRectangle(mMenuButton.x, mMenuButton.y, mMenuButton.width, mMenuButton.height, WHITE);
	DrawText(TextFormat("RESTART"), mRestartButton.x + 125, mRestartButton.y + 35, 30, BLACK);
	DrawText(TextFormat("MAIN MENU"), mMenuButton.x + 110, mMenuButton.y + 35, 30, BLACK);
}