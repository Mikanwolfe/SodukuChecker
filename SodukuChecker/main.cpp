//Sudoku Checker

#include <iostream>

using namespace std;

bool checkRow(int lBoard[9][9], int rowIndex) {
	int rowArray[9] = { 0 };
	int element = 0;
	bool isGood = true;

	for (int i = 0; i < 9; i++) {
		element = lBoard[rowIndex][i];
		if (element != 0) {
			rowArray[element-1]++;
			if (rowArray[element - 1] > 1) {
				isGood = false;
				cout << "Faulty row element found at: (Row,Column)" << i + 1  << ", " << rowIndex + 1 << endl;
			}
		}
	}
	return isGood;
}

bool checkColumn(int lBoard[9][9], int columnIndex) {
	int columnArray[9] = { 0 };
	int element = 0;
	bool isGood = true;

	for (int i = 0; i < 9; i++) {
		element = lBoard[i][columnIndex];
		if (element != 0) {
			columnArray[element - 1]++;
			if (columnArray[element - 1] > 1) {
				isGood = false;
				cout << "Faulty column element found at: (Row,Column)" << i + 1 << ", "<< columnIndex + 1 <<  endl;
			}
		}
	}
	return isGood;
}

bool checkSquare(int lBoard[9][9], int squareIndex) {
	int squareArray[9] = { 0 };
	int element = 0, xPos = 0, yPos = 0, i = 0, j = 0;
	bool isGood = true;
	/* Indexing:| 
	i = -> j =  v

	012
	345
	678
	
	therefore for the full square:
	012 | 345 | 678

	*/
	i = squareIndex % 3;
	j = (int)(squareIndex / 3);
	//cout << "ij:" << i << j << endl;
	for (int k = 0; k < 9; k++) {

		xPos = i * 3 + (k % 3);
		yPos = j * 3 + (int)(k / 3);
		//cout << "xpos:" << xPos << "ypos: " << yPos << endl;
		element = lBoard[yPos][xPos];
		if (element != 0) {
			squareArray[element - 1]++;
			if (squareArray[element - 1] > 1) {
				isGood = false;
				cout << "Faulty square element found at: (Row,Column)" << xPos + 1 << ", " << yPos + 1 << endl;
			}
		}
			
	}
	return isGood;
}

bool checkBoard(int lBoard[9][9]) {
	//returns 'true' if board is good
	int i = 0;
	bool isGood = true;
	i = 0;
	while (i < 9 && isGood) {
		isGood = checkRow(lBoard, i);
		i++;
	}

	i = 0;
	while (i < 9 && isGood) {
		isGood = checkColumn(lBoard, i);
		i++;
	}

	i = 0;
	while (i < 9 && isGood) {
		isGood = checkSquare(lBoard, i);
		i++;
	}
	return isGood;
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