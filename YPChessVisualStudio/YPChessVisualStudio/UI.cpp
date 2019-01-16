#include "UI.h"


UI::UI(State* state)
{
	UI::state = state;
	UI::outputH = GetStdHandle(STD_OUTPUT_HANDLE);
}


UI::~UI()
{
}

void UI::drawBoard()
{
	int pieceCode;
	int squareColor = 0;

	for (int i = 8; i > 0; i--)
	{
		cout << j;
		for (int j = 8; j > 0; j--)
		{
			if (squareColor == 0)
			{
				SetConsoleTextAttribute(outputH, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				squareColor = 1;
			}
			else {
				SetConsoleTextAttribute(outputH, BACKGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
				squareColor = 0;
			}
			pieceCode = state[i][j].getPiece(i, j).getCode();
			cout << " ";
			switch (pieceCode)
			{

			}
		}
	}
}
