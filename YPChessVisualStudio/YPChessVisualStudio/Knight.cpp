#include "Knight.h"
#include "State.h"



Knight::~Knight()
{
}

void Knight::genMoves(std::list<Move*>& moves, Square * square, State * board, int color)
{
	int yStart = square->getRow();
	int xStart = square->getColumn();
	int moveTableY, moveTableX;

	for (int i = 0; i < 8; i++)
	{
		moveTableY = moveTable[i][0];
		moveTableX = moveTable[i][1];
		if (yStart + moveTableY >= 0 && yStart + moveTableY <= 7
			&& xStart + moveTableX >= 0 && xStart + moveTableX <= 7)
		{
			if (board->getPiece(yStart + moveTableY, xStart + moveTableX) == nullptr || board->getPiece(yStart + moveTableY, xStart + moveTableX)->getColor() != color)
			{
				moves.push_back(new Move(square, new Square(yStart + moveTableY, xStart + moveTableX)));
			}
		}
	}
}
