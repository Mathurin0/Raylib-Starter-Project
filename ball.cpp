#include "ball.h"

Ball::Ball() {
	Init();
}

Ball::~Ball() {

}

void Ball::Init() {
	mPosition.x = 960;
	mPosition.y = 987;
	mSpeedX = 0;
	mSpeedY = 0;
	mRadius = BALL_RADIUS;
}

void Ball::Move() {
	mPosition.x += mSpeedX;
	mPosition.y += mSpeedY;
}

void Ball::BounceX() {
	mSpeedX *= -1;
}

void Ball::BounceY() {
	mSpeedY *= -1;
}

void Ball::RandXBounce() {
	mSpeedX += rand() % 3 + (-3);
	mSpeedY += .1f;

	if (mSpeedX > BALL_SPEED * 2) {
		mSpeedX = BALL_SPEED * 2;
	}
	else if (mSpeedX < -BALL_SPEED * 2) {
		mSpeedX = -BALL_SPEED * 2;
	}
}

Vector2 Ball::GetPosition() {
	return mPosition;
}

void Ball::Launch() {
	mSpeedX = BALL_SPEED;
	mSpeedY = -BALL_SPEED;
}

float Ball::GetRadius() {
	return mRadius;
}

void Ball::Draw() {
	DrawCircle(mPosition.x, mPosition.y, BALL_RADIUS, OBJECTS_COLOR);
}

void Ball::Replace(Rectangle paddleRect) {
	mPosition.y = 990;

	if (mPosition.x < paddleRect.x) {
		mPosition.x = paddleRect.x;
	}

	if (mPosition.x > paddleRect.x + paddleRect.width) {
		mPosition.x = paddleRect.x + paddleRect.width;
	}
}

void Ball::PlaceTopPaddle(Rectangle paddleRect) {
	mPosition.y = 987;
	mPosition.x = paddleRect.x + (paddleRect.width / 2);
}