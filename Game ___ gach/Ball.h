#pragma once
#include "primary_Func.h"

#define BALL_ID 178

#define X_START 0
#define X_END 80
#define Y_START 0
#define Y_END 20

extern bool BOARD[Y_END + 1][X_END + 1];

class Ball
{
private:
	int _x, _y;
	int _direct_x;
	int _direct_y;
public:
	Ball();
	void draw();
	void erase();
	bool is_horizon_impact(int next_x, int next_y);
	bool is_vertical_impact(int next_x, int next_y);
	void handle();
	~Ball();
};

