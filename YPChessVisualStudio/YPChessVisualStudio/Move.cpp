#include "Move.h"



Move::Move()
{
}

Move::Move(Square* start, Square* end)
{
	startSquare = start;
	endSquare = end;
}

Move::Move(bool shortCastle, bool longCastle)
{
	Move::shortCastle = shortCastle;
	Move::longCastle = longCastle;
}


Move::~Move()
{
}

Square* Move::getStartSquare()
{
	return Move::startSquare;
}

Square* Move::getEndSquare()
{
	return Move::endSquare;
}

bool Move::isShortCastle()
{
	return Move::isShortCastle;
}

bool Move::isLongCastle()
{
	return Move::isLongCastle;
}
