#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(wchar_t unicode, int color, int code) : Piece(unicode, color, code) {}
	~Bishop();
	void genMoves(std::list<Move>& moves, Square* square, State* board, int color) override;
};

