//Sudoku Checker

#include <iostream>

using namespace std;

bool checkBoard(int lBoard[9][9]) {


	return false;
}

bool checkRow(int lBoard[9][9], int rowIndex) {
	return false;
}

bool checkColumn(int lBoard[9][9], int columnIndex) {
	return false;
}

bool checkSquare(int lBoard[9][9], int squareIndex) {
	return false;
}

int main() {
	int lBoard[9][9] = {
		{ 5, 0, 0, 8, 0, 0, 7, 9, 0 },
		{ 0, 0, 0, 1, 0, 0, 0, 3, 0 },
		{ 0, 6, 9, 0, 0, 0, 8, 0, 0 },
		{ 0, 4, 0, 6, 3, 0, 0, 0, 0 },
		{ 1, 0, 2, 0, 0, 0, 3, 0, 6 },
		{ 0, 0, 0, 0, 5, 1, 0, 7, 0 },
		{ 0, 0, 1, 0, 0, 0, 9, 2, 0 },
		{ 0, 2, 0, 0, 0, 4, 0, 0, 0 },
		{ 0, 9, 6, 0, 0, 3, 0, 0, 8 }
	};

	if (checkBoard(lBoard)) {
		cout << "The board is in a correct configuration" << endl;
	}
	else {
		cout << "The board is in an incorrect configuration" << endl;
	}
	return 0;
}