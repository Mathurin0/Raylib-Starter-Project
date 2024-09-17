#include "brick.h"

Brick::Brick(int x, int y) {
	Init(x, y);
}

Brick::~Brick() {

}

void Brick::Init(int x, int y) {
	mRect.x = x;
	mRect.y = y;
	mRect.width = BRICK_WIDTH;
	mRect.height = BRICK_HEIGHT;
}

Rectangle Brick::GetRect() {
	return mRect;
}

void Brick::Draw() {
	DrawRectangle(mRect.x, mRect.y, mRect.width, mRect.height, OBJECTS_COLOR);
}