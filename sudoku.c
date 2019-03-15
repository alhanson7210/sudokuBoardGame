#include<stdio.h>
void intitializeBoard(int board[9][9]);
void start(int board[]);
void createSudokuPuzzle(int board[9][9], int row, int col);
void display(int board[9][9]);
addInitialValue(int board[9][9], int row, int col, int value);
addGuess(int board[9][9], int rol, int col, int value);
boolean checkPuzzle(int board[9][9]);
int getValueIn(int board[9][9], int rol, int col);
int[] getAllowedValues(int board[9][9], int rol, int col);
isFull(int board[9][9]);
void reset(int board[9][9]);

void intitializeBoard(int board[9][9]) {
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++)
			board[row][col] = 0;
	}
}

void start(int board[]) {

}

void createSudokuPuzzle(int board[9][9], int row, int col) {

}

void display(int board[9][9]) {
	for(int row = 0; row < 9; row++) {
                for(int col = 0; col < 9; col++)
                        printf("%d\t", board[row][col]);
        }
}

addInitialValue(int board[9][9], int row, int col, int value) {
	
}

addGuess(int board[9][9], int rol, int col, int value) {

}

boolean checkPuzzle(int board[9][9]) {

}

int getValueIn(int board[9][9], int rol, int col) {

}

int[] getAllowedValues(int board[9][9], int rol, int col) {

}

isFull(int board[9][9]) {

} 

void reset(int board[9][9]) {
	intializeBoard(board);
}

int main() {

}
