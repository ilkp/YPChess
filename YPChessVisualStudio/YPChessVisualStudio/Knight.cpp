#include "Knight.h"



Knight::Knight(wchar_t unicode, int color, int code) : Piece(unicode, color, code)
{
}


Knight::~Knight()
{
}

void Knight::genMoves(std::list<Move>& moves, Square * square, State * board, int color)
{
	int yStart = square->getColumn();
	int xStart = square->getRow();
	for (int y = yStart - 2; y < yStart + 3; y++)
	{
		for (int x = xStart - 2; y < xStart + 3; x++)
		{
			if (y >= 0 && y <= 7 && x >= 0 && x <= 7
				&& (y + x) % 2 != 0
				&& y != 0 && x != 0)
			{
				if (board->getPiece(yStart, xStart) == nullptr || board->getPiece(yStart, xStart)->getColor() != color)
				{
					moves.push_back(Move(yStart, xStart, y, x));
				}
			}
		}
	}
}
