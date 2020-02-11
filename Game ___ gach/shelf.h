#pragma once

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include "kmin_console.h"
#include "Ball.h"
using namespace std;
//thu commit
//######## - DEFINE - #########
#define X_LEFT 3
#define X_RIGHT 43
#define Y_UP 1
#define Y_DOWN 21
#define LENGTH_SHELF 7
#define WIDTH_SHELF 0
#define BLOCK_SHELF (char)223
#define MAX 250
//////////////////////////////

//######## CLASS OBJECT HERE LUN ######
class object {
protected: 
	//int BOARD[MAX][MAX];
public:

};
///////////////////////////////////////

class shelf : object{
private:
	int x_l, x_r, y_u, y_d;
	int direct= 1;
	void transfer_xy(int a);
	
public:
	void move();
	void initialize();
	void display();
};

