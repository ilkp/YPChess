#include "Rook.h"
#include "State.h"




void Rook::genMoves(std::list<Move*>& moves, Square * square, State * board, int color)
{
	int yStart = square->getRow();
	int xStart = square->getColumn();
	int xDir, yDir, x, y;
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			xDir = -1;
			yDir = 0;
			break;
		case 1:
			xDir = 1;
			yDir = 0;
			break;
		case 2:
			xDir = 0;
			yDir = 1;
			break;
		case 3:
			xDir = 0;
			yDir = -1;
			break;
		default:
			break;
		}

		y = yStart + yDir;
		x = xStart + xDir;
		for (; y > -1 && y < 8 && x > -1 && x < 8; y += yDir, x += xDir)
		{
			if (board->getPiece(y, x) == nullptr)
			{
				moves.push_back(new Move(square, new Square(y, x)));
			}
			else if (board->getPiece(y, x)->getColor() == color)
			{
				break;
			}
			else
			{
				moves.push_back(new Move(square, new Square(y, x)));
				break;
			}
		}
	}
}
