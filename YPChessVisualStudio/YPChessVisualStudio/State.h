#pragma once
#include "Piece.h"
#include "Move.h"

class State
{
private:
	Piece* board[8][8];
	int turn = 0; // 0 = white	1 = black
	bool whiteCastleLeft;
	bool whiteCastleRighT;
	bool blackCastleLeft;
	bool blackCastleRighT;

public:
	State();
	~State();

	Piece* getSquare(int y, int x);
	void setSquare(int y, int x, Piece* piece);
	void updateState(Move* move);
	int getTurn();
	void setTurn(int color);
	bool getWhiteCastleLeft();
	bool getWhiteCastleRight();
	bool getBblackCastleLeft();
	bool getBlackCastleRight();
	Piece* getPiece(int y, int x);

};

