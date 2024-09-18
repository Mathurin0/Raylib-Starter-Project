#include "game.h"

Game::Game() {
	Init();
}

Game::~Game() {

}

void Game::Init() {
	mPaddle = new Paddle();
	mBall = new Ball();
	mGameManager = new GameManager();
	mBallLaunched = false;
	mBall->Launch(); //TODO corriger

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

	// Init life count
	mGameManager->DrawLife();
}

void Game::Update(float deltaTime) {
	/*if (!mBallLaunched && IsKeyDown(KEY_SPACE)) {
		mBall->Launch();
		mBallLaunched = true;
	}*/
	if (IsKeyDown(KEY_RIGHT)) {
		mPaddle->SetPositionX(mPaddle->GetPositionX() + PADDLE_SPEED);

		/*if (!mBallLaunched) {
			mBall->SetPosition(mPaddle->GetPositionX() + mPaddle->GetRect().width / 2, 990);
		}*/
	}
	if (IsKeyDown(KEY_LEFT)) {
		mPaddle->SetPositionX(mPaddle->GetPositionX() - PADDLE_SPEED);

		/*if (!mBallLaunched) {
			mBall->SetPosition(mPaddle->GetPositionX() + mPaddle->GetRect().width / 2, 990);
		}*/
	}

	mBall->Move();

	// Paddle ball bounce
	if (CheckCollisionCircleRec(mBall->GetPosition(), mBall->GetRadius(), mPaddle->GetRect())) {
		mBall->BounceY();
		mBall->Replace(mPaddle->GetRect());
	}

	// Reverse x speed if the ball touch the screen borders
	if (mBall->GetPosition().x >= WINDOW_SIZE.x - BALL_RADIUS || mBall->GetPosition().x <= BALL_RADIUS) {
		mBall->BounceX();
	}
	if (mBall->GetPosition().y <= BALL_RADIUS) {
		mBall->BounceY();
	}

	// Didn't catch the ball
	if (mBall->GetPosition().y >= WINDOW_SIZE.y - BALL_RADIUS) {
		mBall->Init();
		mBall->RandXBounce();
		mGameManager->LoseHealth();
		mBallLaunched = false;
		mBall->Launch(); //TODO corriger
	}


	// Bricks draw and collisions
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

	if (mBricksAmount == 0) {
		mGameManager->WinGame();
	}
}

void Game::Draw() {
	mPaddle->Draw();
	mBall->Draw();
	mGameManager->DrawLife();
}