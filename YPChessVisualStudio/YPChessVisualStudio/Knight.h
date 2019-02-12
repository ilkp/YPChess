#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
	Knight(wchar_t unicode, int color, int code) : Piece(unicode, color, code) {}
	~Knight();
	void genMoves(std::list<Move>& moves, Square* square, State* board, int color) override;
};

