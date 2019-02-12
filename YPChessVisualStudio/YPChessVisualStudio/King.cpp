#include "King.h"



King::King(wchar_t unicode, int color, int code) : Piece(unicode, color, code)
{
}


King::~King()
{
}

void King::genMoves(std::list<Move>& moves, Square * square, State * board, int color)
{
	int yStart = square->getColumn();
	int xStart = square->getRow();
	for (int y = yStart - 1; y < yStart + 2; y++)
	{
		for (int x = xStart - 1; x < xStart + 2; x++)
		{
			if (!(y == 0 && x == 0)
				&& y >= 0 && y <= 7 && x >= 0 && x <= 7
				&& (board->getPiece(y, x) == nullptr || board->getPiece(y, x)->getColor != color))
			{
				moves.push_back(Move(yStart, xStart, y, x));
			}
		}
	}
}
