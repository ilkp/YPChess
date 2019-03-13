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
	return startSquare;
}

Square* Move::getEndSquare()
{
	return endSquare;
}

bool Move::isShortCastle()
{
	return shortCastle;
}

bool Move::isLongCastle()
{
	return longCastle;
}
