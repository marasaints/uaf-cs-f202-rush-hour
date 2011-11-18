#pragma once

#include "myiostuff.h"

class Board
{
public:
	Board(void);
	~Board(void);
	char **board;
	void printBoard(void) const;
};

