#pragma once
#ifndef CONSTANT_H
#define CONSTANT_H

#include <raylib.h>

// GENERAL

const Vector2 WINDOW_SIZE = { 1920, 1080 };
const int FPS_LIMIT = 60;
const Color BACKGROUND_COLOR = DARKBLUE;
const Color OBJECTS_COLOR = WHITE;


// PADDLE

const int PADDLE_WIDTH = 200;
const int PADDLE_HEIGHT = 20;
const int PADDLE_SPEED = 15;


// BALL

const float BALL_RADIUS = 10.0f;
const int BALL_SPEED = 8;


// BRICKS

const int BRICK_HEIGHT = 40;
const int BRICK_WIDTH = 120;
const int BRICKS_SPACING = 4;
const int BRICKS_PER_LINE = 10;
const int BRICKS_AMOUNT = 40;
const int BRICKS_START_Y = 40;
const int BRICKS_START_X = (WINDOW_SIZE.x - (BRICKS_PER_LINE * BRICK_WIDTH + (BRICKS_PER_LINE - 1) * BRICKS_SPACING)) / 2;


#endif