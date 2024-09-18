#include "gameManager.h"
#include "sceneManager.h"

GameManager::GameManager() {
	Init();
}

GameManager::~GameManager() {
	
}

void GameManager::Init() {
	mHealthCount = START_HEALTH;
}

void GameManager::DrawLife() {
	DrawText(TextFormat("Health : %02i", mHealthCount), 20, 20, 40, RED);
}

void GameManager::LoseHealth() {
	mHealthCount--;

	if (mHealthCount == 0) {
		LoseGame();
	}
}

void GameManager::LoseGame() {
	mSceneManager->ChangeScene(LoseScene);
}

void GameManager::WinGame() {
	mSceneManager->ChangeScene(WinScene);
}