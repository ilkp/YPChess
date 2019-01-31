#pragma once
#include "Square.h"

class Move
{
private:
	//Square* startSquare;
	//Square* endSquare;
	int startY;
	int startX;
	int endY;
	int endX;
	int upgrade = 0;
	bool shortCastle;
	bool longCastle;

public:
	Move(int startY, int startX, int endY, int endX);
	//Move(Square* start, Square* end);
	Move(bool shortCastle, bool longCastle);
	~Move();
	//Square* getStartSquare();
	//Square* getEndSquare();
	int getStartY();
	int getStartX();
	int getEndY();
	int getEndX();
	bool isShortCastle();
	bool isLongCastle();
};

