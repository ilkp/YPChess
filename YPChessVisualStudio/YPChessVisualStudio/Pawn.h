#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
	Pawn(wchar_t unicode, int color, int code) : Piece(unicode, color, code) {}
	~Pawn();
	void genMoves(std::list<Move>& moves, Square* square, State* board, int color) override;
};

