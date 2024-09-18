#pragma once
#include "scene.h"
#include "gameManager.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "constant.h"

#include <vector>

class Game : public Scene
{
public :
	Game();
	~Game();

	void Init() override;
	void Update(float deltaTime) override;
	void Draw() override;

private :
	Paddle* mPaddle;
	Ball* mBall;
	GameManager* mGameManager;
	std::vector<Brick> mBricks;
	int mBricksAmount;
	bool mBallLaunched;
};

