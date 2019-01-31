#include "Move.h"


/*
Move::Move(Square* start, Square* end)
{
	startSquare = start;
	endSquare = end;
}
*/

Move::Move(int startY, int startX, int endY, int endX)
{
	Move::startY = startY;
	Move::startX = startX;
	Move::endY = endY;
	Move::endX = endX;
	Move::shortCastle = false;
	Move::longCastle = false;
}

Move::Move(bool shortCastle, bool longCastle)
{
	Move::shortCastle = shortCastle;
	Move::longCastle = longCastle;
}


Move::~Move()
{
}

/*
Square* Move::getStartSquare()
{
	return Move::startSquare;
}

Square* Move::getEndSquare()
{
	return Move::endSquare;
}
*/

int Move::getStartY()
{
	return startY;
}

int Move::getStartX()
{
	return startX;
}

int Move::getEndY()
{
	return endY;
}

int Move::getEndX()
{
	return endX;
}

bool Move::isShortCastle()
{
	return Move::shortCastle;
}

bool Move::isLongCastle()
{
	return Move::longCastle;
}
