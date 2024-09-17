#include "ball.h"

Ball::Ball() {
	Init();
}

Ball::~Ball() {

}

void Ball::Init() {
	mPosition.x = 960;
	mPosition.y = 800;
	mSpeedX = BALL_SPEED;
	mSpeedY = -BALL_SPEED;
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
	mSpeedX += rand() % 2 + (-1);
}

Vector2 Ball::GetPosition() {
	return mPosition;
}

float Ball::GetRadius() {
	return mRadius;
}

void Ball::Draw() {
	DrawCircle(mPosition.x, mPosition.y, BALL_RADIUS, OBJECTS_COLOR);
}