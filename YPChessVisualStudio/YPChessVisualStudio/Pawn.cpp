#include "Pawn.h"
#include "State.h"




Pawn::~Pawn()
{
}

void Pawn::genMoves(std::list<Move*>& moves, Square* square, State* board, int color)
{
	int yStart = square->getRow();
	int xStart = square->getColumn();

	if (color == 0 && square->getRow() != 0)
	{
		if (board->getPiece(yStart - 1, xStart) == nullptr)
		{
			moves.push_back(new Move(square, new Square(yStart - 1, xStart)));
		}
		if (xStart > 0 && board->getPiece(yStart - 1, xStart - 1) != nullptr && board->getPiece(yStart - 1, xStart - 1)->getColor() != color)
		{
			moves.push_back(new Move(square, new Square(yStart - 1, xStart - 1)));
		}
		if (xStart < 7 && board->getPiece(yStart - 1, xStart + 1) != nullptr && board->getPiece(yStart - 1, xStart + 1)->getColor() != color)
		{
			moves.push_back(new Move(square, new Square(yStart - 1, xStart + 1)));
		}
		if (yStart == 6 && board->getPiece(yStart - 1, xStart) == nullptr && board->getPiece(yStart - 2, xStart) == nullptr)
		{
			moves.push_back(new Move(square, new Square(yStart - 2, xStart)));
		}
		if (board->getDoubleStepOnColumn() == xStart - 1 && yStart == 3 && xStart > 0)
		{
			moves.push_back(new Move(square, new Square(yStart - 1, xStart - 1)));
		}
		if (board->getDoubleStepOnColumn() == xStart + 1 && yStart == 3)
		{
			moves.push_back(new Move(square, new Square(yStart - 1, xStart + 1)));
		}
	}
	if (color == 1 && square->getRow() != 7)
	{
		if (board->getPiece(yStart + 1, xStart) == nullptr)
		{
			moves.push_back(new Move(square, new Square(yStart + 1, xStart)));
		}
		if (xStart > 0 && board->getPiece(yStart + 1, xStart - 1) != nullptr && board->getPiece(yStart + 1, xStart - 1)->getColor() != color)
		{
			moves.push_back(new Move(square, new Square(yStart + 1, xStart - 1)));
		}
		if (xStart < 7 && board->getPiece(yStart + 1, xStart + 1) != nullptr && board->getPiece(yStart + 1, xStart + 1)->getColor() != color)
		{
			moves.push_back(new Move(square, new Square(yStart + 1, xStart + 1)));
		}
		if (yStart == 1 && board->getPiece(yStart + 1, xStart) == nullptr && board->getPiece(yStart + 2, xStart) == nullptr)
		{
			moves.push_back(new Move(square, new Square(yStart + 2, xStart)));
		}
		if (board->getDoubleStepOnColumn() == xStart - 1 && yStart == 4 && xStart > 0)
		{
			moves.push_back(new Move(square, new Square(yStart + 1, xStart - 1)));
		}
		if (board->getDoubleStepOnColumn() == xStart + 1 && yStart == 4)
		{
			moves.push_back(new Move(square, new Square(yStart + 1, xStart + 1)));
		}
	}
}
