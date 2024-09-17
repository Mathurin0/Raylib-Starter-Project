#pragma once
#include "constant.h"

class Paddle
{
public :
	Paddle();
	~Paddle();
	
	void SetPositionX(int xPos);
	int GetPositionX();
	Rectangle GetRect();
	
	void Draw();

private :
	Rectangle mRect;
};