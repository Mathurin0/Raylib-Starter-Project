#include "paddle.h"

Paddle::Paddle() {
	mRect.y = 1000;
	mRect.x = 860;
	mRect.width = PADDLE_WIDTH;
	mRect.height = PADDLE_HEIGHT;
}

Paddle::~Paddle() {

}

void Paddle::SetPositionX(int xPos) {
	mRect.x = xPos;

	if (mRect.x < 0) {
		mRect.x = 0;
	}
	else if (mRect.x > 1720) {
		mRect.x = 1720;
	}
}

int Paddle::GetPositionX() {
	return mRect.x;
}

Rectangle Paddle::GetRect() {
	return mRect;
}

void Paddle::Draw() {
	DrawRectangle(mRect.x, mRect.y, mRect.width, mRect.height, OBJECTS_COLOR);
}