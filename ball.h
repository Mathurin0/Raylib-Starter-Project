#pragma once
#include "constant.h"

#include <cstdlib>

class Ball
{
public :
	Ball();
	~Ball();

	void Move();
	void BounceX();
	void BounceY();
	void RandXBounce();

	Vector2 GetPosition();
	float GetRadius();

	void Init();
	void Draw();

private :
	Vector2 mPosition;
	float mRadius;
	float mSpeedX;
	float mSpeedY;
};