
#include "Piece.h"
#include "State.h"
#include "UI.h"
#include "Minimax.h"
#include <iostream>
#include <vector>

using namespace std;


int main()
{
	std::vector<State*> previousStates;

	State* state = new State();
	UI* ui = new UI(state, GetStdHandle(STD_OUTPUT_HANDLE));
	Move* move;
	int playerSide;

	cout << "Pelaajan puoli (0 valkoinen, 1 musta): ";
	cin >> playerSide;


	while (true)
	{
		if (state->getTurn() == playerSide)
		{
			previousStates.push_back(new State(*state));
			ui->drawBoard(state);
			do {
				move = ui->takePlayersMove();
				if (move->getStartSquare()->getColumn() == -1)
				{
					previousStates.pop_back();
					state = previousStates.back();
					break;
				}
			} while (!state->moveIsLegal(move));
			if (move->getStartSquare()->getColumn() != -1)
			{
				state->playMove(move);
				state->setTurn((state->getTurn() + 1) % 2);
			}
			delete(move);
		}
		else {
			ui->drawBoard(state);
			Minimax minimax = state->minimax(2);
			state->playMove(&minimax.bestMove);
			state->setTurn((state->getTurn() + 1) % 2);
		}
	}
	ui->drawBoard(state);
	
	int end;
	cin >> end;
	return 0;
}