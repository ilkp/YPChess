#pragma once

#include <string>

using namespace std;

enum
{
	WKING, WQUEEN, WBISHOP, WKNIGHT, WROOK, WPAWN,
	BKING, BQUEEN, BBISHOP, BKNIGHT, BROOK, BPAWN
};

class Piece
{
private:
	wchar_t unicode;
	int color; // 0 = white		1 = black
	int code;

public:
	Piece(wchar_t unicode, int color, int code);
	~Piece();
	void setCode(int code);
	int getCode();
	void setUnicode(wchar_t unicode);
	wchar_t getUnicode();
	void setColor(int color);
	int getColor();
};

