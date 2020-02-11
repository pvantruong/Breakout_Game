#include "shelf.h"

void shelf::initialize() {
	x_l = (X_LEFT + X_RIGHT) - LENGTH_SHELF / 2;
	x_r = x_l + LENGTH_SHELF;
	y_d = Y_DOWN - WIDTH_SHELF;
	y_u = y_d -  WIDTH_SHELF;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			BOARD[i][j] = FALSE;
		}
	}
	for (int x = x_l - 1; x <= x_r; x++) {
		for (int y = y_u; y <= y_d; y++) {
			BOARD[x][y] = TRUE;
		}
	}
}
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
				BOARD[x_r][i] = FALSE;
				BOARD[x_l - 1][i] = TRUE;
			}
			transfer_xy(-1);
			direct = -1;
			
			break;
		case 'd':
			for (int i = y_u; i <= y_d; i++) {
				BOARD[x_r +1][i] = TRUE;
				BOARD[x_l][i] = FALSE;
			}
			transfer_xy(1);
			direct = 1;
			break;
	}
}
// xl = 11; xr = 16; y_d = 10; y_u = 9;
void shelf::display() {
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
