#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
	Rook() {};
	Rook(wchar_t unicode, int color, int code) : Piece(unicode, color, code) {}
	void genMoves(std::list<Move*>& moves, Square* square, State* board, int color);
};

