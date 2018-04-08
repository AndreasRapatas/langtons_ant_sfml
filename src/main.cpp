#include <iostream>
#include <vector>
#include <random>

#include "board_model.h"

using namespace std;


int main() {

	Board board(10, 10, 1);

	for (int i = 0; i < 10; i++) {
		board.step();
	}

	return 0;
}
