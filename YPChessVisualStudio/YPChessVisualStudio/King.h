#pragma once
#include "Piece.h"
class King : public Piece
{
public:
	King(wchar_t unicode, int color, int code) : Piece(unicode, color, code) {}
	~King();
	void genMoves(std::list<Move>& moves, Square* square, State* board, int color) override;
};

