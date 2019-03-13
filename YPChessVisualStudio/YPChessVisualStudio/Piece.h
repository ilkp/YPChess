#pragma once

#include <string>
#include <list>

#include "Move.h"


class State;

class Piece
{
private:
	wchar_t unicode;
	int color; // 0 = white		1 = black
	int code;

public:
	enum code
	{
		KING, QUEEN, BISHOP, KNIGHT, ROOK, PAWN
	};

	Piece() {};
	Piece(wchar_t unicode, int color, int code);
	Piece(const Piece& other);
	~Piece();
	void setCode(int code);
	int getCode();
	void setUnicode(wchar_t unicode);
	wchar_t getUnicode();
	void setColor(int color);
	int getColor();
	virtual void genMoves(std::list<Move*>& moves, Square* square, State* board, int color) = 0;

};

