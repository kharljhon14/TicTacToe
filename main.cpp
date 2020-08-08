#include <iostream>
#include <string>

using namespace std;

const int ROW = 3;
const int COL = 3;

void runGame();
void initializeGameBoard(string _gameBoard[ROW][COL]);
void printCurrentGameBoard(string _gameBoard[ROW][COL]);
void userInput(bool& xTurn, string _gameBoard[ROW][COL]);
bool cellAlreadyOccupied(int _row, int _col, string _gameBoard[ROW][COL]);
string getWinner(string _gameBoard[ROW][COL]);
bool isBoardFull(string _gameBoard[ROW][COL]);

int main()
{
	runGame();
	return 0;
}

void runGame()
{
	bool xTurn = false;
	string gameBoard[ROW][COL];	

	initializeGameBoard(gameBoard);
	cout << "O turns" << endl;

	while (getWinner(gameBoard) == "" && !isBoardFull(gameBoard))
	{
		printCurrentGameBoard(gameBoard);
		userInput(xTurn, gameBoard);
	}

	system("cls");
	printCurrentGameBoard(gameBoard);

	if(getWinner(gameBoard) == "" && isBoardFull(gameBoard)) // if has no winner and there are no move count
		cout << endl << "Cat's game"<< endl;

	if (getWinner(gameBoard) != "") //print the winner
		cout << endl << getWinner(gameBoard) << " is the winner" << endl;
}

void initializeGameBoard(string _gameBoard[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			_gameBoard[i][j] = " "; // initialize the 2d array to be blank spaces
		}
	}
}

void printCurrentGameBoard(string _gameBoard[ROW][COL])
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << _gameBoard[i][j]; // print X/O or blank
			if (j < 2)
				cout << " | "; // print 2x
		}

		cout << endl;

		if (i < 2)// print 2x
			cout << "- - - - -" << endl;
	}
}

void userInput(bool& xTurn, string _gameBoard[ROW][COL])
{
	int row, col;
	cin >> row;
	cin >> col;

	while ((row >= ROW || col >= COL) || (row < 0 || col < 0) || !cellAlreadyOccupied(row, col, _gameBoard)) // check if input is valid
	{
		cout << "Try Again!" << endl;
		cin >> row;
		cin >> col;
	}

	if (xTurn)
	{
		_gameBoard[row][col] = "X"; // print X in array position
		cout << "O turns" << endl;
	}

	else
	{
		_gameBoard[row][col] = "O";// print O in array position
		cout << "X turns" << endl;
	}
	xTurn = !xTurn;
}

bool cellAlreadyOccupied(int _row, int _col, string _gameBoard[ROW][COL])
{
	if (_gameBoard[_row][_col] != "X" && _gameBoard[_row][_col] != "O")   //check if board has an element  
		return 1; 
	else
		return 0;
}

string getWinner(string _gameBoard[ROW][COL]) // get the winner
{
	for (int i = 0; i < ROW; i++)
	{
		if (_gameBoard[i][0] != " " && _gameBoard[i][0] == _gameBoard[i][1] && _gameBoard[i][1] == _gameBoard[i][2])
			return _gameBoard[i][0]; //horizontal match
	}

	for (int j = 0; j < COL; j++)
	{
		if (_gameBoard[0][j] != " " && _gameBoard[0][j] == _gameBoard[1][j] && _gameBoard[1][j] == _gameBoard[2][j])
			return _gameBoard[0][j]; //vertical match
	}

	if (_gameBoard[0][0] != " " && _gameBoard[0][0] == _gameBoard[1][1] && _gameBoard[1][1] == _gameBoard[2][2])
		return _gameBoard[0][0]; // diagonal match // upper left to lower right

	if (_gameBoard[2][0] != " " && _gameBoard[2][0] == _gameBoard[1][1] && _gameBoard[1][1] == _gameBoard[0][2])
		return _gameBoard[2][0]; // diagonal match // upper lower left to upper right

	return "";
}

bool isBoardFull(string _gameBoard[ROW][COL])
{
	int cellOccupied = 0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (_gameBoard[i][j] != " ")
				cellOccupied++;     //count how many cells are occupied

			if (cellOccupied == 9)
				return 1;		
		}	
	}
	return 0;
}
