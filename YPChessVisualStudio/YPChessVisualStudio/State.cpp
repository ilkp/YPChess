#include "State.h"
#include "Move.h"
#include <iostream>
#include <string>

using namespace std;

/*
WKING		L'\u2654'
WQUEEN		L'\u2655'
WROOK		L'\u2656'
WBISHOP		L'\u2657'
WKNIGHT		L'\u2658'
WPAWN		L'\u2659'

BKING		L'\u265A'
BQUEEN		L'\u265B'
BROOK		L'\u265C'
BBISHOP		L'\u265D'
BKNIGHT		L'\u265E'
BPAWN		L'\u265F'
*/

State::State()
{
	board[0][0] = new Piece(L'\u265C', 1, BROOK);
	board[0][1] = new Piece(L'\u265E', 1, BKNIGHT);
	board[0][2] = new Piece(L'\u265D', 1, BBISHOP);
	board[0][3] = new Piece(L'\u265B', 1, BQUEEN);
	board[0][4] = new Piece(L'\u265A', 1, BKING);
	board[0][5] = new Piece(L'\u265D', 1, BBISHOP);
	board[0][6] = new Piece(L'\u265E', 1, BKNIGHT);
	board[0][7] = new Piece(L'\u265C', 1, BROOK);

	board[7][0] = new Piece(L'\u2656', 0, WROOK);
	board[7][1] = new Piece(L'\u2658', 0, WKNIGHT);
	board[7][2] = new Piece(L'\u2657', 0, WBISHOP);
	board[7][3] = new Piece(L'\u2655', 0, WQUEEN);
	board[7][4] = new Piece(L'\u2654', 0, WKING);
	board[7][5] = new Piece(L'\u2657', 0, WBISHOP);
	board[7][6] = new Piece(L'\u2658', 0, WKNIGHT);
	board[7][7] = new Piece(L'\u2656', 0, WROOK);

	for (int i = 0; i < 8; i++)
	{
		board[1][i] = new Piece(L'\u265F', 1, BPAWN);
		board[6][i] = new Piece(L'\u2659', 0, WPAWN);
	}

	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = 0;
		}
	}
}



State::~State()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (board[i][j] != 0)
			{
				delete(board[i][j]);
			}
		}
	}
}

void State::setSquare(int y, int x, Piece* piece)
{
	board[y][x] = piece;
}

void State::updateState(Move* move)
{
	if (move->isLongCastle())
	{
		if (turn == 0)
		{
			board[7][2] = board[7][4];
			board[7][4] = 0;
			board[7][3] = board[7][0];
			board[7][0] = 0;
		}
		else {
			board[0][2] = board[0][4];
			board[0][4] = 0;
			board[0][3] = board[0][0];
			board[0][0] = 0;
		}
	}
	else if (move->isShortCastle())
	{
		if (turn == 0)
		{
			board[7][6] = board[7][4];
			board[7][4] = 0;
			board[7][5] = board[7][7];
			board[7][7] = 0;
		}
		else {
			board[0][6] = board[0][4];
			board[0][4] = 0;
			board[0][5] = board[0][7];
			board[0][7] = 0;
		}
	}
	else {
		board[move->getEndSquare()->getRow()][move->getEndSquare()->getColumn()]
			= board[move->getStartSquare()->getRow()][move->getStartSquare()->getColumn()];
		board[move->getStartSquare()->getRow()][move->getStartSquare()->getColumn()] = 0;
	}
}

int State::getTurn()
{
	return turn;
}

void State::setTurn(int color)
{
	// 0 = white, 1 = black
	State::turn = color;
}

bool State::getWhiteCastleLeft()
{
	return false;
}

bool State::getWhiteCastleRight()
{
	return false;
}

bool State::getBblackCastleLeft()
{
	return false;
}

bool State::getBlackCastleRight()
{
	return false;
}

Piece* State::getPiece(int y, int x)
{
	return board[y][x];
}

Piece* State::getSquare(int y, int x)
{
	if (board[y][x] == NULL)
	{
		return NULL;
	}
	else;
	{
		return board[y][x];
	}
	
}
