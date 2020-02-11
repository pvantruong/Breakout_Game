#include "brick.h"

void brick::initialize() {
	for (int i = 0; i < NUM_BRICK_X; i++) {
		for (int j = 0; j < NUM_BRICK_Y; j++) {
			matrix_brick[i][j].x = X_LEFT + i * LENGTH_BRICK + i*DISTANCE_BRICK_X;
			matrix_brick[i][j].y = Y_UP + j * WIDTH_BRICK + j*DISTANCE_BRICK_Y;
		}
	}
}
void brick::read_map() {
	ifstream file_brick;
	file_brick.open("brick_01.txt", ios::in);
	for (int i = 0; i < NUM_BRICK_Y; i++) {
		getline(file_brick, brick_data[i]);
	}
	file_brick.close();
	for (int j = 0; j < NUM_BRICK_Y; j++) {
		for (int i = 0; i < NUM_BRICK_X; i++) {
			matrix_brick[i][j].block = brick_data[j][i]-48;
		}
	}
}

void brick::display() {
	for (int i = 0; i < NUM_BRICK_X; i++) {
		for (int j = 0; j < NUM_BRICK_Y; j++) {
			for (int a = 0; a < LENGTH_BRICK; a++) {
				for (int b = 0; b < WIDTH_BRICK; b++) {
					//FILL BOARD:
					
					//DISPLAY:
					gotoXY(matrix_brick[i][j].x + a, matrix_brick[i][j].y + b);
					if (matrix_brick[i][j].block == 1) {
						cout << BLOCK_SELF;
					}
					else { cout << " "; }
					
				}
			}
		}
	}
}
