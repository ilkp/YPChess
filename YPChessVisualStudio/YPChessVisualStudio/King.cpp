#include "King.h"
#include "State.h"




King::~King()
{
}

void King::genMoves(std::list<Move*>& moves, Square * square, State * board, int color)
{
	int yStart = square->getRow();
	int xStart = square->getColumn();
	for (int y = yStart - 1; y < yStart + 2; y++)
	{
		for (int x = xStart - 1; x < xStart + 2; x++)
		{
			if (!(y == 0 && x == 0)
				&& y >= 0 && y <= 7 && x >= 0 && x <= 7
				&& (board->getPiece(y, x) == nullptr || board->getPiece(y, x)->getColor() != color))
			{
				moves.push_back(new Move(square, new Square(y, x)));
			}
		}
	}

	if (color == 0)
	{
		if (!board->getWhiteKingMoved())
		{
			if (!board->getWhiteQRMoved()
				&& board->getPiece(7, 1) == nullptr
				&& board->getPiece(7, 2) == nullptr
				&& board->getPiece(7, 3) == nullptr)
			{
				moves.push_back(new Move(0, 1));
			}
			if (!board->getWhiteKRMoved()
				&& board->getPiece(7, 6) == nullptr
				&& board->getPiece(7, 5) == nullptr)
			{
				moves.push_back(new Move(1, 0));
			}
		}
	}
	else {
		if (!board->getBlackKingMoved())
		{
			if (!board->getBlackQRMoved()
				&& board->getPiece(0, 1) == nullptr
				&& board->getPiece(0, 2) == nullptr
				&& board->getPiece(0, 3) == nullptr)
			{
				moves.push_back(new Move(0, 1));
			}
			if (!board->getBlackKRMoved()
				&& board->getPiece(0, 6) == nullptr
				&& board->getPiece(0, 5) == nullptr)
			{
				moves.push_back(new Move(1, 0));
			}
		}
	}
}
