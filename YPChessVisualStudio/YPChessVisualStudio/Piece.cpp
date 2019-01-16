#include "Piece.h"





Piece::Piece(wstring unicode, int color, int code)
{
	Piece::unicode = unicode;
	Piece::color = color;
	Piece::code = code;
}

Piece::~Piece()
{
}

void Piece::setCode(int code)
{
	Piece::code = code;
}

int Piece::getCode()
{
	return code;
}

void Piece::setUnicode(wstring unicode)
{
	Piece::unicode = unicode;
}

wstring Piece::getUnicode()
{
	return unicode;
}

void Piece::setColor(int color)
{
	Piece::color = color;
}

int Piece::getColor()
{
	return color;
}
