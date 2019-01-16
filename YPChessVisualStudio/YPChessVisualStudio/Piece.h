#pragma once

#include <string>

using namespace std;

enum
{
	WK, WQ, WB, Wk, WT, WS,
	BK, BQ, BB, Bk, BT, BS
};

class Piece
{
private:
	wstring unicode;
	int color;
	int code;

public:
	Piece(wstring unicode, int color, int code);
	~Piece();
	void setCode(int code);
	int getCode();
	void setUnicode(wstring unicode);
	wstring getUnicode();
	void setColor(int color);
	int getColor();
};

