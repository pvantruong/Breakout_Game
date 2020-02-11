#include "brick.h"
//Khoi tao (x,y) of matrix brick
void brick::initialize() {
	for (int i = 0; i < NUM_BRICK_X; i++) {
		for (int j = 0; j < NUM_BRICK_Y; j++) {
			matrix_brick[i][j].x = X_LEFT + i * LENGTH_BRICK + i*DISTANCE_BRICK_X + 1;
			matrix_brick[i][j].y = Y_UP + j * WIDTH_BRICK + j*DISTANCE_BRICK_Y + 1;
		}
	}
}
// Read map
void brick::read_map() {
	ifstream file_brick;
	file_brick.open("brick_01.txt", ios::in);
	for (int i = 0; i < NUM_BRICK_Y; i++) {
		getline(file_brick, brick_data[i]);
	}
	file_brick.close();
	for (int j = 0; j < NUM_BRICK_Y; j++) {
		for (int i = 0; i < NUM_BRICK_X; i++) {
			//Load matrix brick  
			matrix_brick[i][j].block = brick_data[j][i]-48;
		}
	}
}
// Display brick
void brick::display() {
	for (int i = 0; i < NUM_BRICK_X; i++) {
		for (int j = 0; j < NUM_BRICK_Y; j++) {
			for (int a = 0; a < LENGTH_BRICK; a++) {
				for (int b = 0; b < WIDTH_BRICK; b++) {
					//FILL BOARD of brick = 1:
					BOARD[matrix_brick[i][j].x + a][matrix_brick[i][j].y + b] = 1;
					//DISPLAY brick:
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
void wall :: display() {
	//Display & fill BOARD
	for (int x = X_LEFT; x <= X_RIGHT; x++) {
		gotoXY(x, Y_UP);
		cout << BLOCK_NGANG;
		BOARD[x][Y_UP] = 1;
		gotoXY(x, Y_DOWN);
		cout << BLOCK_NGANG;
		BOARD[x][Y_DOWN] = 1;
	}
	for (int y = Y_UP; y <= Y_DOWN; y++) {
		gotoXY(X_LEFT, y);
		cout << BLOCK_DOC;
		BOARD[X_LEFT][y] = 1;
		gotoXY(X_RIGHT, y);
		cout << BLOCK_DOC;
		BOARD[X_RIGHT][y] = 1;
	}
	gotoXY(X_LEFT, Y_UP); cout << BLOCK_GOC_U_L;
	BOARD[X_LEFT][Y_UP] = 1;
	gotoXY(X_LEFT, Y_DOWN); cout << BLOCK_GOC_D_L;
	BOARD[X_LEFT][Y_DOWN] = 1;
	gotoXY(X_RIGHT, Y_UP); cout << BLOCK_GOC_U_R;
	BOARD[X_RIGHT][Y_UP] = 1;
	gotoXY(X_RIGHT, Y_DOWN); cout << BLOCK_GOC_D_R;
	BOARD[X_RIGHT][Y_DOWN] = 1;
}
