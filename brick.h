#pragma once
#include "constant.h"

class Brick
{
public :
	Brick(int x, int y);
	~Brick();

	void Init(int x, int y);
	void Draw();

	Rectangle GetRect();

private :
	Rectangle mRect;
};

