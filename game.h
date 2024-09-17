#pragma once
#include "scene.h"
#include "sceneManager.h"
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
	std::vector<Brick> mBricks;
	int mBricksAmount;
};

