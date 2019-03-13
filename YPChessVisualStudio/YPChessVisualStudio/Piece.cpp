#include "Piece.h"





Piece::Piece(wchar_t unicode, int color, int code)
{
	Piece::unicode = unicode;
	Piece::color = color;
	Piece::code = code;
}

Piece::Piece(const Piece & other)
{
	this->unicode = other.unicode;
	this->color = other.color;
	this->code = other.code;
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

void Piece::setUnicode(wchar_t unicode)
{
	Piece::unicode = unicode;
}

wchar_t Piece::getUnicode()
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
