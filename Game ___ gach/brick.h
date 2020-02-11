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
#define NUM_BRICK_X 10
#define NUM_BRICK_Y 4
#define LENGTH_BRICK 6
#define WIDTH_BRICK 2
#define DISTANCE_BRICK_X 1
#define DISTANCE_BRICK_Y 1
#define BLOCK_SELF (char)219
#define BLOCK_NGANG (char)205
#define BLOCK_DOC (char)186
#define BLOCK_GOC_U_L (char)201
#define BLOCK_GOC_U_R (char)187
#define BLOCK_GOC_D_L (char)200
#define BLOCK_GOC_D_R (char)188
////////////////////////////////
struct matrix {
	int x, y;
	int block = 0;
};
// CLASS BRICK
class brick : object{
private:
	matrix matrix_brick[NUM_BRICK_X][NUM_BRICK_Y];
	string brick_data[NUM_BRICK_Y];
public:
	void initialize();
	void read_map();
	void display();
};
// CLASS WALL
class wall : object {
private:
public:
	void display();
};

