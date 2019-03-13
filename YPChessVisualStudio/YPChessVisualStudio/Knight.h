#pragma once
#include "Piece.h"
class Knight : public Piece
{
private:
	int moveTable[8][2] = { {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2}, {2, -1}, {2, 1} };
public:
	Knight(wchar_t unicode, int color, int code) : Piece(unicode, color, code) {}
	~Knight();
	void genMoves(std::list<Move*>& moves, Square* square, State* board, int color);
};

