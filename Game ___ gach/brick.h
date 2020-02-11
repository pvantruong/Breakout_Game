#pragma once
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include "kmin_console.h"
#include "shelf.h"
using namespace std;

//######## - DEFINE - #########
#define X_LEFT 3
#define X_RIGHT 73
#define Y_UP 1
#define Y_DOWN 21
#define NUM_BRICK_X 10
#define NUM_BRICK_Y 4
#define LENGTH_BRICK 6
#define WIDTH_BRICK 2
#define DISTANCE_BRICK_X 1
#define DISTANCE_BRICK_Y 1
#define BLOCK_SELF (char)219
////////////////////////////////
struct matrix {
	int x, y;
	int block = 0;
};
class brick : object{
private:
	matrix matrix_brick[NUM_BRICK_X][NUM_BRICK_Y];
	string brick_data[NUM_BRICK_Y];
public:
	void initialize();
	void read_map();
	void display();
};

