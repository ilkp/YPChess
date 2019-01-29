#include "UI.h"
#include <string>
#include <io.h>
#include <fcntl.h>

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

Move * UI::giveOpponentsMove()
{
	return nullptr;
}
