#pragma once
class Square
{
private:
	int row;
	int column;

public:
	Square(int row, int column);
	Square();
	~Square();
	int getRow();
	int getColumn();
};

