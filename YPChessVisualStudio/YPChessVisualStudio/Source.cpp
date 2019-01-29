
#include "Piece.h"
#include "State.h"
#include "UI.h"
#include <iostream>

using namespace std;


int main()
{
	State* state = new State();
	UI* ui = new UI(state, GetStdHandle(STD_OUTPUT_HANDLE));

	ui->drawBoard();
	
	int end;
	cin >> end;
	return 0;
}