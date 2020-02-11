#include "shelf.h"
#include "brick.h"

void main() {
	noCursorType();
	shelf aa;
	brick bb;
	wall cc;
	cc.display();
	aa.initialize();
	bb.initialize();
	bb.read_map();
	bb.display();
	while (1) {
		aa.display();
		aa.move();
	}
}
