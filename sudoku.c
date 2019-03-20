#include <stdio.h>
#include <stdlib.h>
void intitializeBoard(int board[9][9], int ninjaBoard[9][9]);
void start(int board[9][9], int ninjaBoard[9][9]);
void createSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]);
void display(int board[9][9]);
void addInitialValue(int board[9][9], int ninjaBoard[9][9], int row, int col, int value);
void addGuess(int board[9][9], int ninjaBoard[9][9], int row, int col, int value);
boolean checkPuzzle(int board[9][9], int ninjaBoard[9][9]);
int getValueIn(int board[9][9], int row, int col);
int[] getAllowedValues(int board[9][9], int row, int col);
boolean isFull(int ninjaBoard[9][9]);
void reset(int board[9][9], int ninjaBoard[9][9]);
void displaySingleArray(int arr[], int n);
void initializeCounterArray(int counterArray[9]);
boolean checkRowAndColumn(int board[9][9], int row, int col, int value);
boolean checkGrid(int board[9][9], int row, int col);
void randomizedSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]);

void displaySingleArray(int arr[], int n) {
  for(int i = 0; i < n; i++) {
    printf("arr[%d] is %d.\n", i, arr[i]);
  }
}

void initializeCounterArray(int counterArray[9]) {
	for(int i = 0; i < 9; i++)
		counterArray[i] = 0;
}

void intitializeBoard(int board[9][9], int ninjaBoard[9][9]) {
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++) {
			board[row][col] = 0;
			ninjaBoard[row][col] = 0;
		}
	}
}

void start(int board[9][9], int ninjaBoard[9][9]) {
	intializeBoard(board, ninjaBoard);
	//createSudokuPuzzle(board,ninjaBoard);
}

void randomizedSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]) {
	int counter = 36, row = rand() , col = rand(), value = rand(), position;
	while (counter != 0) {
		while(row < 1 || row > 9)
			row = rand();

		while(col < 1 || col > 9)
			col = rand();

		while(value < 1 || value > 9)
			value = rand();

		position = getValueIn(ninjaBoard, row, col);

		while(position != 0) {
			while(row < 1 || row > 9)
                        	row = rand();
                	while(col < 1 || col > 9)
                        	col = rand();
                	while(value < 1 || value > 9)
                        	value = rand();
                	position = getValueIn(ninjaBoard, row, col);
		}

		while(!checkRowAndColumn(board, row, col, value)){
			while(position != 0) {
                        	while(row < 1 || row > 9)
                               		row = rand();
                        	while(col < 1 || col > 9)
                                	col = rand();
                        	while(value < 1 || value > 9)
                                	value = rand();
                        	position = getValueIn(ninjaBoard, row, col);
                	}
		}
		addInitial(board, ninjaBoard, row, col, value);
		counter--;
	}
}
boolean checkRowAndColumn(int board[9][9], int row, int col, int value){
	//rows
	for(int x = 0; x < 9; x++){
		if(x != row){
			if(getValueIn(board,x,col) == value)
				return false;
                }
        }
        //columns
        for(int y = 0; y < 9; y++){
        	if(y != col){
			if(getValueIn(board,row,y) == value)
				return false;
                }
        }
	return true;
}
void createSudokuPuzzle(int board[9][9], int ninjaBoard[9][9]) {
	addInitialValue(board, ninjaBoard, 0, 1, 6);
	addInitialValue(board, ninjaBoard, 0, 2, 8);
	addInitialValue(board, ninjaBoard, 0, 6, 9);
	addInitialValue(board, ninjaBoard, 0, 7, 3);
	addInitialValue(board, ninjaBoard, 1, 1, 4);
	addInitialValue(board, ninjaBoard, 1, 2, 2);

        addInitialValue(board, ninjaBoard, 1, 6, 6);
        addInitialValue(board, ninjaBoard, 2, 0, 1);
        addInitialValue(board, ninjaBoard, 2, 1, 9);
        addInitialValue(board, ninjaBoard, 2, 4, 8);
        addInitialValue(board, ninjaBoard, 2, 7, 4);
        addInitialValue(board, ninjaBoard, 3, 1, 8);

        addInitialValue(board, ninjaBoard, 3, 2, 5);
        addInitialValue(board, ninjaBoard, 3, 3, 2);
        addInitialValue(board, ninjaBoard, 3, 5, 1);
        addInitialValue(board, ninjaBoard, 3, 8, 7);
        addInitialValue(board, ninjaBoard, 4, 0, 7);
        addInitialValue(board, ninjaBoard, 4, 3, 8);

        addInitialValue(board, ninjaBoard, 4, 4, 9);
        addInitialValue(board, ninjaBoard, 5, 0, 2);
        addInitialValue(board, ninjaBoard, 5, 2, 9);
        addInitialValue(board, ninjaBoard, 5, 5, 7);
        addInitialValue(board, ninjaBoard, 5, 6, 5);
        addInitialValue(board, ninjaBoard, 5, 8, 3);

        addInitialValue(board, ninjaBoard, 6, 1, 2);
        addInitialValue(board, ninjaBoard, 6, 3, 1);
        addInitialValue(board, ninjaBoard, 6, 7, 5);
        addInitialValue(board, ninjaBoard, 7, 0, 8);
        addInitialValue(board, ninjaBoard, 7, 1, 5);
        addInitialValue(board, ninjaBoard, 7, 4, 4);

        addInitialValue(board, ninjaBoard, 7, 6, 7);
        addInitialValue(board, ninjaBoard, 7, 7, 6);
        addInitialValue(board, ninjaBoard, 8, 0, 4);
        addInitialValue(board, ninjaBoard, 8, 1, 7);
        addInitialValue(board, ninjaBoard, 8, 2, 3);
        addInitialValue(board, ninjaBoard, 8, 4, 5);

	addInitialValue(board, ninjaBoard, 8, 5, 2);
	addInitialValue(board, ninjaBoard, 8, 8, 9);
}

void display(int board[9][9]) {
	for(int row = 0; row < 9; row++) {
                for(int col = 0; col < 9; col++)
                        printf("%d\t", board[row][col]);
        }
}

void addInitialValue(int board[9][9], int ninjaBoard[9][9], int row, int col, int value) {
	board[row][col] = value;
	ninjaBoard[row][col] = -1;
}

void addGuess(int board[9][9], int ninjaBoard[9][9], int row, int col, int value) {
	if(getValueIn(ninjaBoard,row,col) > -1) {
		board[row][col] = value;
		ninjaBoard[row][col] = 1;
	}
}
boolean checkGrid(int board[9][9], int row, int col) {
	int countingArray[9];
        intializeCounterArray(countingArray);
	for(int r= row; r <= row+2; r++){
		for(int c= col; r <= col+2; c++){
			int cell = getValueIn(board,r,c);
                        if(cell != 0)
                                countingArray[cell-1]++;
		}
	}
	for(int i = 0; i < 9; i++){        
                if(countingArray[i] > 1)
                	return false;
        }
	return true;
}

boolean checkPuzzle(int board[9][9], int ninjaBoard[9][9]) {
	//checking the grid
	if(!isFull(ninjaBoard)){
		for(int x = 0; x <= 6; x+3){
			for(int y = 0; y <= 6; y+3){
				if(checkGrid(board,x,y) == false)
					return false;
			}
		}
	}
	//checking all rows and columns
	else{
		for(int row = 0; row < 9; row++) {
			int countingArray[9];
			//counting the occurences in the column
			intializeCounterArray(countingArray);
                	for(int col = 0; col < 9; col++){
				int cell = getValueIn(board,row,col);
				if(cell != 0)
					countingArray[cell-1]++;
			}
			for(int i = 0; i < 9; i++){
				if(countingArray[i] > 1)
					return false;
			}
			//counting the occuences in the row
			intializeCounterArray(countingArray);
                	for(int col = 0; col < 9; col++){
                	        int cell = getValueIn(board,col,row);
                	        if(cell != 0)
                	                countingArray[cell-1]++;
                	}
                	for(int i = 0; i < 9; i++){
                	        if(countingArray[i] > 1)
                	                return false;
                	}
		}
		return true;
	}
}

int getValueIn(int board[9][9], int row, int col) {
	return board[row][col];
}

int[] getAllowedValues(int board[9][9], int ninjaBoard[9][9], int row, int col) {
	int collinderArray[17], countingArray[9], unduplicatedArray[9], temp[9];
	int collinderArray[0] = getValueIn(board, row, col);
	int counter 1;
	while (counter < 17) {
		//rows
		for(int x = 0; x < 9; x++){
			if(x != row){
				collinderArray[counter] = getValueIn(board,x,col);
				counter++;
			}
		}
		//columns
		for(int y = 0; y < 9; y++){
			if(y != col){
				collinderArray[counter] = getValueIn(board,row,y);
				counter++;
			}
		}
	}
	for(int j = 0; j < 9; j++)
		countingArray[i] = 0;
	
	for(int i = 0; i < 17; i++) {
		countingArray[collinderArray[i]-1]++;
	}
	
	for(int z = 0; z < 9; z++){
		if(countingArray[i] > 0)
			unduplicatedArray[z] = z+1;
		else
			unduplicated[z] = 0;
	}
	counter = 0;
	for(int f = 0; f < 9; f++){
		if(unduplicatedArray[f] == 0){
			temp[counter] = f+1;
			counter++;
		}
	}
	return temp;
}

boolean isFull(int ninjaBoard[9][9]) {
	for(int r = 0; r < 9; r++){
		for(int c = 0; c < 9; c++){
			if(getValueIn(ninjaBoard,r,c) == 0)
				return false;
		}
	}
	return true;
} 

void reset(int board[9][9], int ninjaBoard[9][9]) {
	intializeBoard(board);
	intializeBoard(ninjaBoard);
}

int main() {

}
