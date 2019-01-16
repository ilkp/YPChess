#include "State.h"
#include <iostream>
#include <wstring>
using namespace std;



State::State()
{
	board = new Piece*[8][8];
}


State::~State()
{
}

Piece State::getBoard()
{
	return Piece();
}

void State::setBoard(Piece * board)
{
}

void State::setSquare(int x, int y, Piece* piece)
{
	board[x][y] = piece;
}

int State::getPiece(int x, int y)
{
	if (board[x][y] == NULL)
	{
		return NULL;
	}
	else;
	{
		return ;
	}
	
}
