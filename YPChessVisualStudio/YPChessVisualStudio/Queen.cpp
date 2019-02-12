#include "Queen.h"



Queen::Queen(wchar_t unicode, int color, int code) : Piece(unicode, color, code)
{
}


Queen::~Queen()
{
}

void Queen::genMoves(std::list<Move>& moves, Square * square, State * board, int color)
{
	Rook::genMoves(moves, square, board, color);
	Bishop::genMoves(moves, square, board, color);
}
