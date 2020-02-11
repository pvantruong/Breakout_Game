#include "shelf.h"


//KHOI TAO TAO DO, 
void shelf::initialize() {
	x_l = (X_RIGHT - X_LEFT)/2 - LENGTH_SHELF / 2;
	x_r = x_l + LENGTH_SHELF;
	y_d = Y_DOWN - 1;
	y_u = y_d -  WIDTH_SHELF;
	//khoi tao all board = 0
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			BOARD[i][j] = 0;
		}
	}
	//Set board of shelf = 1
	for (int x = x_l - 1; x <= x_r; x++) {
		for (int y = y_u; y <= y_d; y++) {
			BOARD[x][y] = true;
		}
	}
}
// Func dich chuyen x, y (viet de sau nay add func of moving up down thi de them)
void shelf::transfer_xy(int a) {
	x_l += a;
	x_r += a;
}
void shelf::move()
{
	char type_ = '\n';
	type_ = _getch();
	switch (type_) {
		case 'a':
			for (int i = y_u; i <= y_d; i++) {
				BOARD[x_r][i] = 0;
				BOARD[x_l - 1][i] = 1;
			}
			transfer_xy(-1);
			direct = -1;
			
			break;
		case 'd':
			for (int i = y_u; i <= y_d; i++) {
				BOARD[x_r +1][i] = 1;
				BOARD[x_l][i] = 0;
			}
			transfer_xy(1);
			direct = 1;
			break;
	}
}
//Dispaly shelf 
void shelf::display() {
	// Xet direct dich chuyen shelf de cout "_" 
	if (direct == 1) {
		for (int x = x_l - 1; x <= x_r; x++) {
			for (int y = y_u; y <= y_d; y++) {
				gotoXY(x, y);
				if (x == x_l - 1) { cout << " "; } 
				else {
					cout << BLOCK_SHELF;
				}
			}
		}
	}
	else if (direct == -1) {
		for (int x = x_l; x <= x_r + 1; x++) {
			for (int y = y_u; y <= y_d; y++) {
				gotoXY(x, y);
				if (x == x_r + 1) { cout << " "; }
				else {
					cout << BLOCK_SHELF;
				}
			}
		}
	}
	
}
