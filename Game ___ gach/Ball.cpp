#include "Ball.h"

bool BOARD[Y_END + 1][X_END + 1];


Ball::Ball() 
{
	_x = _y = 1;
	_direct_x = _direct_y = 1;
}

Ball::~Ball() 
{
}

void Ball::draw()
{
	gotoXY(_x, _y);
	cout << (char)BALL_ID;
}

void Ball::erase()
{
	del(_x, _y, 1);
}

bool Ball::is_horizon_impact(int next_x, int next_y)
{
	if ((next_x + 1 <= X_END && BOARD[next_y][next_x + 1] == true)
		|| (next_x - 1 >= X_START && BOARD[next_y][next_x - 1] == true))
		return true;
	else return false;
}

bool Ball::is_vertical_impact(int next_x, int next_y)
{
	if ((next_y + 1 <= Y_END && BOARD[next_y + 1][next_x] == true)
		|| (next_y - 1 >= Y_START && BOARD[next_y - 1][next_x] == true))
		return true;
	else return false;
}

void Ball::handle()
{
	int next_x = _x + _direct_x;
	int next_y = _y + _direct_y;

	if (BOARD[next_y][next_x] == true)
	{
		if (is_horizon_impact(next_x, next_y)) _direct_y = -_direct_y;
		if (is_vertical_impact(next_x, next_y)) _direct_x = -_direct_x;
		next_x = _x + _direct_x;
		next_y = _y + _direct_y;
	}
	_x = next_x;
	_y = next_y;
}