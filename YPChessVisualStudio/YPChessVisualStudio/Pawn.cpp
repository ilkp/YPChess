#include "Pawn.h"



Pawn::Pawn(wchar_t unicode, int color, int code) : Piece(unicode, color, code)
{
}


Pawn::~Pawn()
{
}

void Pawn::genMoves(std::list<Move>& moves, Square* square, State* board, int color)
{
	int yStart = square->getColumn();
	int xStart = square->getRow();

	if (color == 0 && square->getColumn() != 0)
	{
		if (board->getPiece(yStart - 1, xStart) == nullptr)
		{
			moves.push_back(Move(yStart, xStart, yStart - 1, xStart));
		}
		if (board->getPiece(yStart - 1, xStart - 1) != nullptr && board->getPiece(yStart - 1, xStart - 1)->getColor() != color)
		{
			moves.push_back(Move(yStart, xStart, yStart - 1, xStart - 1));
		}
		if (board->getPiece(yStart - 1, xStart + 1) != nullptr && board->getPiece(yStart - 1, xStart + 1)->getColor() != color)
		{
			moves.push_back(Move(yStart, xStart, yStart - 1, xStart + 1));
		}
	}
	if (color == 1 && square->getColumn() != 7)
	{
		if (board->getPiece(yStart + 1, xStart) == nullptr)
		{
			moves.push_back(Move(yStart, xStart, yStart + 1, xStart));
		}
		if (board->getPiece(yStart + 1, xStart - 1) != nullptr && board->getPiece(yStart + 1, xStart - 1)->getColor() != color)
		{
			moves.push_back(Move(yStart, xStart, yStart + 1, xStart - 1));
		}
		if (board->getPiece(yStart + 1, xStart + 1) != nullptr && board->getPiece(yStart + 1, xStart + 1)->getColor() != color)
		{
			moves.push_back(Move(yStart, xStart, yStart + 1, xStart + 1));
		}
	}
}
