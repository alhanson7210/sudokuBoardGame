#include<stdio.h>
#include <stdlib.h>
void intitializeBoard(int board[9][9], int ninjaboard[9][9]);
void initalizeCounterArray(int countingarray[9]);
void start(int board[9][9], int ninjaboard[9][9]);
void createSudokuPuzzle(int board[9][9], int ninjaboard[9][9], int row, int col);
void display(int board[9][9]);
addInitialValue(int board[9][9], int ninjaboard[9][9], int row, int col, int value);
addGuess(int board[9][9], int ninjaboard[9][9], int row, int col, int value);
boolean checkPuzzle(int board[9][9]);
int getValueIn(int board[9][9], int row, int col);
int[] getAllowedValues(int board[9][9], int ninjaboard[9][9], int row, int col);
isFull(int board[9][9], row, col);
void reset(int board[9][9]);
void displaySingleArray(int arr[], int size); 
boolean CheckRowAndColumn(int board, int row, int col, int value);

void intitializeBoard(int board[9][9], int ninjaboard[9][9]) {
	for(int row = 0; row < 9; row++) {
		for(int col = 0; col < 9; col++)
			board[row][col] = 0;
			ninjaboard[row][col] = 0;


	}
}

void start(int board[9][9], int ninjaboard[9][9]) {
	intitializeBoard(board, ninjaboard);
	createSudokuPuzzle(addInitialValue);


}

void randomizedSudokuPuzzle(int board[9][9], int ninjaboard[9][9]){
	int counter = 36, row = rand(), col = rand(), value = rand(), position;
	while (counter != 0){
		while(row < 1 || row > 9){
			row = rand();
		}

		while(col < 1 || col > 9){
			col = rand();
		}

		while( value < 1 || value > 9){
			value = rand();
		}
		position = getValueIn(ninjaboard, row, col);
		while(position != 0){
			while(row < 1 || row > 9){
				row = rand();
			}

			while(col < 1 || col > 9){
				col = rand();
			}

			while( value < 1 || value > 9){
				value = rand();
			}
			position = getValueIn(ninjaboard, row, col);

		}
		
		while(CheckRowAndColumn(board, row, col, value)){
			while(position != 0){
			while(row < 1 || row > 9){
				row = rand();
			}

			while(col < 1 || col > 9){
				col = rand();
			}

			while( value < 1 || value > 9){
				value = rand();
			}
			position = getValueIn(ninjaboard, row, col);
			
		}
		addInitialValue(board, ninjaboard, row, col, value);
		counter --;
	} 

}

boolean CheckRowAndColumn(int board, int row, int col, int value){
	for(int x = 0; x < 9; x++){
		if(x != row){
			getValueIn(board, x, col) = value;
			return false;
		}
	}
	//columns
	for(int y = 0; y < 9; y++){
		if(y != col){
			getValueIn(board, row, y) = value;
			return false;
		}	
	}

	return true;
}



void createSudokuPuzzle(int board[9][9], int ninjaboard[9][9]) { //where the random part comes in
	addInitialValue(board, ninjaboard, 0, 1, 6);
	addInitialValue(board, ninjaboard, 0, 2, 8);
	addInitialValue(board, ninjaboard, 0, 6, 9);
	addInitialValue(board, ninjaboard, 0, 7, 3);
	addInitialValue(board, ninjaboard, 1, 1, 4);
	addInitialValue(board, ninjaboard, 1, 2, 2);
	
	addInitialValue(board, ninjaboard, 1, 6, 6);
	addInitialValue(board, ninjaboard, 2, 0, 9);
	addInitialValue(board, ninjaboard, 2, 1, 9);
	addInitialValue(board, ninjaboard, 2, 4, 8);
	addInitialValue(board, ninjaboard, 2, 7, 4);
	addInitialValue(board, ninjaboard, 3, 1, 8);
	
	addInitialValue(board, ninjaboard, 3, 2, 5);
	addInitialValue(board, ninjaboard, 3, 3, 2);
	addInitialValue(board, ninjaboard, 3, 5, 1);
	addInitialValue(board, ninjaboard, 3, 8, 7);
	addInitialValue(board, ninjaboard, 4, 0, 7);
	addInitialValue(board, ninjaboard, 4, 3, 8);
	
	addInitialValue(board, ninjaboard, 4, 4, 9);
	addInitialValue(board, ninjaboard, 5, 0, 2);
	addInitialValue(board, ninjaboard, 5, 2, 9);
	addInitialValue(board, ninjaboard, 5, 5, 7);
	addInitialValue(board, ninjaboard, 5, 6, 5);
	addInitialValue(board, ninjaboard, 5, 8, 3);
	
	addInitialValue(board, ninjaboard, 6, 1, 2);
	addInitialValue(board, ninjaboard, 6, 3, 1);
	addInitialValue(board, ninjaboard, 6, 7, 5);
	addInitialValue(board, ninjaboard, 7, 0, 8);
	addInitialValue(board, ninjaboard, 7, 1, 5);
	addInitialValue(board, ninjaboard, 7, 4, 4);
	
	addInitialValue(board, ninjaboard, 7, 6, 7);
	addInitialValue(board, ninjaboard, 7, 7, 6);
	addInitialValue(board, ninjaboard, 8, 0, 4);
	addInitialValue(board, ninjaboard, 8, 1, 7);
	addInitialValue(board, ninjaboard, 8, 2, 3);
	addInitialValue(board, ninjaboard, 8, 4, 5);
	
	addInitialValue(board, ninjaboard, 8, 5, 2);
	addInitialValue(board, ninjaboard, 8, 8, 9);


}



void display(int board[9][9]) {
	for(int row = 0; row < 9; row++) {
                for(int col = 0; col < 9; col++)
                        printf("%d\t", board[row][col]);
        }
}

void addInitialValue(int board[9][9], int ninjaboard[9][9], int row, int col, int value) {
	board[row][col] = value;
	ninjaboard = -1;
}

void addGuess(int board[9][9], int ninjaboard[9][9], int row, int col, int value) {
	if(getValueIn(ninjaboard, row, column) > -1) {
		board[row][column] = value;
		ninjaboard = 1;
	}

}

void initalizeCountingArray(int countingarray[9]){
	for(int i = 0; i < 9; i++){
		countingarray[i] = 0;
	}
}

boolean ckeckGrid(int board[9][9]){
	int countingarray[9];
	initalizeCounterArray(countingarray);
	for(int r = row; r <= row+2; r++){
		for(int c = col; c <= col+2; c++){
			int cell = getValueIn(board, r, c);
			if(cell != 0){
				countingarray[cell-1]++;
			}

		}
		for(int i = 0; i < 9; i++){
			if(countingarray[i] > 1){
				return false;
	}

	return true;
}


boolean checkPuzzle(int board[9][9], ninjaboard[9][9]) {
	//checkinhg the grid
	if(isFull(ninjaboard)){
		for(int x = 0; x <= 6; x+3){
			for(int y = 0; y <=6; y+3){
				checkGrid(board, x, y);

				if(checkGrid == false){
					return fale;
				}
			}
		}

	}
	
	else{//counting the occuranecs in the particular column
		for(int row = 0; row < 9; row++){
			int countingarray[9];
			initalizeCounterArray(countingarray);
			for(col = 0; col < 9; col++){
				int cell = getValueIn(board, row, col);
				if(cell != 0){
					countingarray[cell-1]++;
				}
			}

			for(int i = 0; i < 9; i++){
				if(countingarray[i] > 1){
					return false;
				}
			}

			//checking the poccurances in the particular row 
			initalizeCounterArray(countingarray);
			for(col = 0; col < 9; col++){
				int cell = getValueIn(board, col, row);
				if(cell != 0){
					countingarray[cell-1]++;
				}
			}

			for(int i = 0; i < 9; i++){
				if(countingarray[i] > 1){
					return false;
				}
			}
		
		}
		return true;

	}


}

int getValueIn(int board[9][9], int row, int col) {
	return board[row][col];


}

void displaySingleArray(int arr[], int size){
	for(int i = 0; i < n; i++){
		printf("Your array element arr[%d] is %d.\n", i, array[i]);
	}
}



int[] getAllowedValues(int board[9][9], int ninjaboard[9][9], int row, int col) {
	int colanderarray[17], countingarray[9], unduplicatedarray[9], temp[9];
	int colanderarray[0] = getValueIn(board, row, col);
	int counter = 1;
	while(counter < 17){
		//rows
		for(int x = 0; x < 9; x++){
			if(x != row){
			colanderarray[counter] = getValueIn(board, x, col);
			counter ++;
			}
		}
			//columns
		for(int y = 0; y < 9; y++){
			if(y != col){
				colanderarray[counter] = getValueIn(board, row, y);
				counter++;
			}	

		}
	}
	for(int j = 0; j < 9; j++)
		countingarray[i] = 0;
	
	for(int i = 0; i < 17; i++){
		countingarray[colanderarray[i]-1]++;
	}

	for(int z = 0; z < 9; z++){
		if(countingarray[i] > 0){
			unduplicatedarray[z] = z+1;
		}
		else{
			unduplicatedarray[z] = 0;
		}
	}

	counter = 0;
	for(int f = 0; f < 9; f++){
		if(unduplicatedarray[f] = 0){
			temp[counter] = f+1; 
			counter ++;
			
		}
	}

	return temp;

}

boolean isFull(int ninjaboard[9][9]) {
	for(int r = 0; r < 9; r++){
		for(int c = 0; c < 9; c++){
			if(getValueIn(ninjaboard, r, c) == 0){
				return false;
			}
		}

		return true;
	}



} 

void reset(int board[9][9]) {
	intializeBoard(board);
	intializeBoard(ninjaboard);
}

int main() {
	printf("\n");
	
	printf("===============================\n"
		   ">> HELLO! WELCOME TO SODOKU! <<!\n"
	       "===============================\n");
	
	printf("\n");

	printf("Your instructions are as follows:\n"
		"\n"
		"1 - Each block (3X3) must have the numbers 1-9.\n"
		"2 - Each row and column must also have the numbers 1-9.\n"
		"3 - the numbers 1-9 in any block (3x3) or any row or column must not be repeated.\n"
		"\n"
		"Begin playing and have fun!\n");

	while(isFull == false){

	}

}