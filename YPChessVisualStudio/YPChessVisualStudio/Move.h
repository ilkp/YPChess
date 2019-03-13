#pragma once
#include "Square.h"

class Move
{
private:
	Square* startSquare;
	Square* endSquare;
	int endY;
	int endX;
	int upgrade = 0;
	bool shortCastle;
	bool longCastle;

public:
	Move();
	Move(Square* start, Square* end);
	Move(bool shortCastle, bool longCastle);
	~Move();
	Square* getStartSquare();
	Square* getEndSquare();
	bool isShortCastle();
	bool isLongCastle();
};

