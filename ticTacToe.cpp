 

//Tic-Tac-Toe Implementation file

#include <iostream>
#include <iomanip> 
#include <random>
#include "ticTacToe.h"

using namespace std;

void ticTacToe::play()
{
    bool done = false;

    char player = 'X';
    displayBoard();

    while (!done){
        done = getXOMove(player);
        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }
}

void ticTacToe::displayBoard() const{

    cout << "  0   1   2 " << endl;
	for (int row = 0; row < 3; row++)
	{
		cout << row;
		for (int col = 0; col < 3; col++)
		{
			cout << setw(3) << board[row][col];
			if (col != 2)
				cout << "|";

		}

		//End of the row
		cout << endl;
		if (row != 2)
			cout << " -----------" << endl;
	}
	cout << endl;
}




bool ticTacToe::isValidMove(int row, int col) const{


	//checking if its out of boudns:
	if (row < 0 || row > 2 || col < 0 || col > 2) {
		return false;
	}


	//check if space is empty
	else if (board[row][col] != ' ') {
		return false;
	}

	else {
		return true;
	}
}

bool ticTacToe::getXOMove(char playerSymbol){


	int row, col;
	bool validMove = false;

	do{
		cout << "Player " << playerSymbol << " enter move: ";
		cin >> row >> col;
		validMove = isValidMove(row, col);
		if (!validMove)
			cout << "Invalid move. Try again." << endl;
	} while (!validMove);
	board[row][col] = playerSymbol;
	noOfMoves++;
	displayBoard();



	if (gameStatus() == WIN)
	{
		cout << "Player " << playerSymbol << " wins!" << endl;
		return true;
	}
	else if (gameStatus() == DRAW)
	{
		cout << "The game is a draw." << endl;
		return true;
	}
	else
		return false;
}

status ticTacToe::gameStatus(){
	//Check for a win
	for (int row = 0; row < 3; row++)
	{
		if (board[row][0] == board[row][1] && board[row][0] == board[row][2] && board[row][0] != ' ')
			return WIN;
	}
}

void ticTacToe::reStart()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}

ticTacToe::ticTacToe()
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            board[row][col] = ' ';

    noOfMoves = 0;
}
