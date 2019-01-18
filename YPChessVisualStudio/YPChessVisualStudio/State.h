#pragma once
#include "Piece.h"

class State
{
private:

	Piece* VK;
	Piece* VD;
	Piece* VT;
	Piece* VL;
	Piece* VR;
	Piece* VS;
	Piece* MK;
	Piece* MD;
	Piece* MT;
	Piece* ML;
	Piece* MR;
	Piece* MS;

	/*
	VK, L"\u2654	
	VD, L"\u2655	
	VT, L"\u2656	 
	VL, L"\u2657	
	VR, L"\u2658	
	VS, L"\u2659"
	MK, L"\u265A	
	MD, L"\u265B
	MT, L"\u265C”
	ML, L"\u265D"
	MR, L"\u265E"
	MS, L"\u265F"
	*/

	Piece* board[8][8];


public:
	State();
	~State();

	Piece getBoard();

	void setBoard(Piece* board);

	void setSquare(int x, int y, Piece* piece);

	Piece getPiece(int x, int y);
};

