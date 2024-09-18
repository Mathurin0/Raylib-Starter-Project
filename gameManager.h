#pragma once
#include "constant.h"

#include <string>

class GameManager
{
public :
	GameManager();
	~GameManager();

	void LoseHealth();
	void LoseGame();
	void WinGame();

	void Init();
	void DrawLife();

private :
	int mHealthCount;
};

