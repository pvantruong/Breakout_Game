#pragma once
#include "basic_func.h"

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
	int _direct_x;			//Đơn vị di chuyển của x, chỉ có thể là 1 hoặc -1
	int _direct_y;			//Đơn vị di chuyển của y, chỉ có thể là 1 hoặc -1
public:
	Ball();
	void draw();
	void erase();
	bool is_horizon_impact(int next_x, int next_y);		//kiểm tra là va chạm hai bên
	bool is_vertical_impact(int next_x, int next_y);	//kiểm tra là va chạm trên dưới
	void handle();
	void xuli();
	~Ball();
};

