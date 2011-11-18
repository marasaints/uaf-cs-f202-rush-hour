#include "Board.h"


Board::Board(void)
{
	board = new char* [8];
	for (int i = 0; i < 8; ++i)
	{
		board[i] = new char [8];
	}
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			if (i == 0 || i == 7)
			{
				board[i][j] = '@';
			}
			else if(i == 3 && j == 7)
			{
				board[i][j] = '.';
			}
			else if(j == 0 || j == 7)
			{
				board[i][j] = '@';
			}
			else
			{
				board[i][j] = ' ';
			}
		}
	}

}


Board::~Board(void)
{
	for (int i = 0; i < 8; ++i)
	{
		delete board[i];
	}
	delete board;
}


void Board::printBoard(void) const
{
	for (int i = 0; i < 8; ++i)
	{
		std::cout << board[i][0];
		for (int j = 1; j < 8; ++j)
		{
			std::cout  << " "<< board[i][j];
		}
		std::cout << "\n";
	}
}
