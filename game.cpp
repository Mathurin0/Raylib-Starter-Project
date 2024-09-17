#include "game.h"

Game::Game() {
	Init();
}

Game::~Game() {

}

void Game::Init() {
	mPaddle = new Paddle();
	mBall = new Ball();

	// Init bricks
	for (int i = 0; i < BRICKS_AMOUNT; i++)
	{
		int linesFinished = (i - (i % BRICKS_PER_LINE)) / BRICKS_PER_LINE;

		mBricks.push_back(Brick(
			BRICKS_START_X + (i % BRICKS_PER_LINE) * BRICK_WIDTH + (i % BRICKS_PER_LINE) * BRICKS_SPACING,
			BRICKS_START_Y + linesFinished * BRICK_HEIGHT + linesFinished * BRICKS_SPACING
		));

		mBricks[i].Draw();
	}
	mBricksAmount = BRICKS_AMOUNT;
}

void Game::Update(float deltaTime) {
	if (IsKeyDown(KEY_RIGHT)) mPaddle->SetPositionX(mPaddle->GetPositionX() + PADDLE_SPEED);
	if (IsKeyDown(KEY_LEFT)) mPaddle->SetPositionX(mPaddle->GetPositionX() - PADDLE_SPEED);

	mBall->Move();

	if (CheckCollisionCircleRec(mBall->GetPosition(), mBall->GetRadius(), mPaddle->GetRect())) {
		mBall->BounceY();
	}

	// Reverse x speed if the ball touch the screen borders
	if (mBall->GetPosition().x >= WINDOW_SIZE.x - BALL_RADIUS || mBall->GetPosition().x <= BALL_RADIUS) {
		mBall->BounceX();
	}
	if (mBall->GetPosition().y <= BALL_RADIUS) {
		mBall->BounceY();
	}
	if (mBall->GetPosition().y >= WINDOW_SIZE.y - BALL_RADIUS) {
		mBall->Init();
		mBall->RandXBounce();
	}

	int indexToDelete = -1;

	for (int i = 0; i < mBricksAmount; i++)
	{
		mBricks[i].Draw();

		if (CheckCollisionCircleRec(mBall->GetPosition(), mBall->GetRadius(), mBricks[i].GetRect())) {
			mBricks[i].~Brick();

			if (mBall->GetPosition().x - BALL_RADIUS < mBricks[i].GetRect().x || mBall->GetPosition().x + BALL_RADIUS > mBricks[i].GetRect().x + BRICK_WIDTH) {
				mBall->BounceX();
			}
			else {
				mBall->BounceY();
			}
			indexToDelete = i;
		}
	}

	if (indexToDelete != -1) {
		mBricks.erase(mBricks.begin() + indexToDelete);
		mBricksAmount--;
	}

	// Reverse x speed if the ball touch any brick and lower the brick health or delete it
}

void Game::Draw() {
	mPaddle->Draw();
	mBall->Draw();
}