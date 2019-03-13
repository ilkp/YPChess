#pragma once

#include <list>
#include "Move.h"
#include "Minimax.h"

class Piece;

class State
{
private:
	Piece* board[8][8];
	int turn = 0; // 0 = white	1 = black
	bool whiteKingMoved = 0;
	bool blackKingMoved = 0;
	bool whiteQRMoved = 0;
	bool whiteKRMoved = 0;
	bool blackQRMoved = 0;
	bool blackKRMoved = 0;
	int doubleStepOnColumn = -1;

public:
	State();
	State(const State& state);
	~State();

	void setSquare(int y, int x, Piece* piece);
	void updateState(Move* move);
	int getTurn();
	void setTurn(int color);
	bool getWhiteKingMoved();
	bool getBlackKingMoved();
	bool getWhiteQRMoved();
	bool getWhiteKRMoved();
	bool getBlackQRMoved();
	bool getBlackKRMoved();
	void giveRawMoves(std::list<Move*>& moves);
	void giveLegalMoves(std::list<Move*>& moves);
	Piece* getPiece(int y, int x);
	Square findKing(int color);
	bool squareThreatened(Square square, std::list<Move*>& moves);
	bool squareThreatened(Square square, int opponent);
	int getDoubleStepOnColumn() { return doubleStepOnColumn; }
	double evaluate();
	Minimax minimax(int depth);
	double endState();
	void playMove(Move* move);
	bool moveIsLegal(Move* move);
};

