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
	UI::hConsole = outputHandle;
}

UI::~UI()
{
}

void UI::drawBoard(State* state)
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
			if (state->getPiece(y, x) != 0)
			{
				wcout << " " << state->getPiece(y, x)->getUnicode() << " ";
			}
			else {
				wcout << "   ";
			}
		}
		wcout << "\n";
	}
	wcout << "  a  b  c  d  e  f  g  h" << endl;
}

Move* UI::takePlayersMove()
{
	string input;
	std::cin >> input;
	if (input == "--")
	{
		return new Move(new Square(-1, -1), new Square(-1, -1));
	}
	if (input == "0-0")
	{
		return new Move(1, 0);
	}
	if (input == "0-0-0")
	{
		return new Move(0, 1);
	}
	int ystart = BOARD_Y(input[1]);
	return new Move(new Square(BOARD_Y(input[1]), BOARD_X(input[0])), new Square(BOARD_Y(input[4]), BOARD_X(input[3])));
}
