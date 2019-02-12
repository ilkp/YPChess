#include "Rook.h"



Rook::Rook(wchar_t unicode, int color, int code) : Piece(unicode, color, code)
{
}


Rook::~Rook()
{
}

void Rook::genMoves(std::list<Move>& moves, Square * square, State * board, int color)
{
	int yStart = square->getColumn();
	int xStart = square->getRow();
	int xDir = -1;
	int yDir = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int y = yStart, x = xStart; y <= 7, y >= 0, x <= 7, x >= 0; y + yDir, x + xDir)
		{
			if (board->getPiece(y, x) == nullptr)
			{
				moves.push_back(Move(yStart, xStart, y, x));
			}
			else if (board->getPiece(y, x)->getColor() == color)
			{
				break;
			}
			else
			{
				moves.push_back(Move(yStart, xStart, y, x));
				break;
			}
		}
		switch (i)
		{
		case 1:
			xDir = 1;
			break;
		case 2:
			xDir = 0;
			yDir = 1;
			break;
		case 3:
			yDir = -1;
			break;
		}
	}
}
