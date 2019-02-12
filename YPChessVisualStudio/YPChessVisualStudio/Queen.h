#pragma once
#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
class Queen : public Rook, public Bishop, public Piece
{
public:
	Queen(wchar_t unicode, int color, int code) : Piece(unicode, color, code) {}
	~Queen();
	void genMoves(std::list<Move>& moves, Square* square, State* board, int color) override;
};

