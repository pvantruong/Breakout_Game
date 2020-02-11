#include "shelf.h"
#include "brick.h"
#include "basic_func.h"
#include "Ball.h"

void thread_func(shelf aa)
{
	while (1) {
		aa.display();
		aa.move();
	}
}

void main() {
	NoCursorType();
	shelf aa;
	brick bb;
	Ball ball;
	aa.initialize();
	bb.initialize();

	ve_khung(0, 0, X_END + 1, Y_END + 1, "big");
	for (int i = 0; i <= Y_END; i++)
		for (int j = 0; j <= X_END; j++)
		{
			if (i == Y_START || i == Y_END) BOARD[i][j] = true;
			else if (j == X_START || j == X_END) BOARD[i][j] = true;
			else BOARD[i][j] = false;
		}

	thread t1(thread_func, ref(aa));
	HANDLE handle_t1 = t1.native_handle();
	//bb.read_map();
	//bb.display();
	while (1) {
		ball.draw();
		Sleep(50);
		ball.erase();
		ball.handle();
		
	}

}
