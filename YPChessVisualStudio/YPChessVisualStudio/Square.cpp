#include "Square.h"



Square::Square()
{
}


Square::Square(int row, int column)
{
	this->row = row;
	this->column = column;
}

Square::~Square()
{
}

int Square::getRow()
{
	return row;
}

int Square::getColumn()
{
	return column;
}
