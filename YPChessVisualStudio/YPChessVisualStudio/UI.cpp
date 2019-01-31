#include "UI.h"
#include "Square.h"
#include <string>
#include <io.h>
#include <fcntl.h>
#include <string>

#define BOARD_Y(x) (7 - (x - 49)) // 7- turns printed board number into internal board number, 4-8 is offset from ascii number
#define BOARD_X(x) (x - 97) // -97 is offset from ascii character

UI::UI(State* state, HANDLE outputHandle)
{
	UI::state = state;
	UI::hConsole = outputHandle;
}

UI::~UI()
{
}

void UI::drawBoard()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	for (int y = 0; y < 8; y++)
	{
		wcout << 8 - y;
		for (int x = 0; x < 8; x++)
		{
			if ((y + x) % 2 == 0)
			{
				SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			else {
				SetConsoleTextAttribute(hConsole, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			}
			if (state->getSquare(y, x) != 0)
			{
				wcout << " " << state->getSquare(y, x)->getUnicode() << " ";
			}
			else {
				wcout << "   ";
			}
		}
		wcout << "\n";
	}
	wcout << "  a  b  c  d  e  f  g  h" << endl;
}

Move* UI::giveOpponentsMove()
{
	string input;
	std::cin >> input;
	if (input[0] == 'O')
	{
		if (input.length() > 3)
		{
			return new Move(0, 1);
		}
		return new Move(1, 0);
	}
	int ystart = BOARD_Y(input[2]);
	return new Move(BOARD_Y(input[2]), BOARD_X(input[1]), BOARD_Y(input[5]), BOARD_X(input[4]));
}
