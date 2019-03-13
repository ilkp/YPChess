#include <iostream>
#include <string>
#include "State.h"
#include "Move.h"
#include "Bishop.h"
#include "King.h"
#include "Knight.h"
#include "Pawn.h"
#include "Queen.h"
#include "Rook.h"


using namespace std;

/*
WKING		L'\u2654'
WQUEEN		L'\u2655'
WROOK		L'\u2656'
WBISHOP		L'\u2657'
WKNIGHT		L'\u2658'
WPAWN		L'\u2659'

BKING		L'\u265A'
BQUEEN		L'\u265B'
BROOK		L'\u265C'
BBISHOP		L'\u265D'
BKNIGHT		L'\u265E'
BPAWN		L'\u265F'
*/

State::State()
{
	board[0][0] = new Rook(L'\u265C', 1, Piece::ROOK);
	board[0][1] = new Knight(L'\u265E', 1, Piece::KNIGHT);
	board[0][2] = new Bishop(L'\u265D', 1, Piece::BISHOP);
	board[0][3] = new Queen(L'\u265B', 1, Piece::QUEEN);
	board[0][4] = new King(L'\u265A', 1, Piece::KING);
	board[0][5] = new Bishop(L'\u265D', 1, Piece::BISHOP);
	board[0][6] = new Knight(L'\u265E', 1, Piece::KNIGHT);
	board[0][7] = new Rook(L'\u265C', 1, Piece::ROOK);

	board[7][0] = new Rook(L'\u2656', 0, Piece::ROOK);
	board[7][1] = new Knight(L'\u2658', 0, Piece::KNIGHT);
	board[7][2] = new Bishop(L'\u2657', 0, Piece::BISHOP);
	board[7][3] = new Queen(L'\u2655', 0, Piece::QUEEN);
	board[7][4] = new King(L'\u2654', 0, Piece::KING);
	board[7][5] = new Bishop(L'\u2657', 0, Piece::BISHOP);
	board[7][6] = new Knight(L'\u2658', 0, Piece::KNIGHT);
	board[7][7] = new Rook(L'\u2656', 0, Piece::ROOK);

	for (int i = 0; i < 8; i++)
	{
		board[1][i] = new Pawn(L'\u265F', 1, Piece::PAWN);
		board[6][i] = new Pawn(L'\u2659', 0, Piece::PAWN);
	}

	for (int i = 2; i < 6; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			board[i][j] = nullptr;
		}
	}
}

State::State(const State & state)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			board[y][x] = state.board[y][x];
		}
	}
	turn = state.turn;
	whiteKingMoved = state.whiteKingMoved;
	blackKingMoved = state.blackKingMoved;
	whiteQRMoved = state.whiteQRMoved;
	whiteKRMoved = state.whiteKRMoved;
	blackQRMoved = state.blackQRMoved;
	blackKRMoved = state.blackKRMoved;
	doubleStepOnColumn = state.doubleStepOnColumn;
}



State::~State()
{
}

void State::setSquare(int y, int x, Piece* piece)
{
	board[y][x] = piece;
}

void State::updateState(Move* move)
{
	if (move->isLongCastle())
	{
		if (turn == 0)
		{
			board[7][2] = board[7][4];
			board[7][4] = 0;
			board[7][3] = board[7][0];
			board[7][0] = 0;
		}
		else {
			board[0][2] = board[0][4];
			board[0][4] = 0;
			board[0][3] = board[0][0];
			board[0][0] = 0;
		}
	}
	else if (move->isShortCastle())
	{
		if (turn == 0)
		{
			board[7][6] = board[7][4];
			board[7][4] = 0;
			board[7][5] = board[7][7];
			board[7][7] = 0;
		}
		else {
			board[0][6] = board[0][4];
			board[0][4] = 0;
			board[0][5] = board[0][7];
			board[0][7] = 0;
		}
	}
	else {
		board[move->getEndSquare()->getRow()][move->getEndSquare()->getColumn()]
			= board[move->getStartSquare()->getRow()][move->getStartSquare()->getColumn()];
		board[move->getStartSquare()->getRow()][move->getStartSquare()->getColumn()] = 0;
	}
}

int State::getTurn()
{
	return turn;
}

void State::setTurn(int color)
{
	// 0 = white, 1 = black
	State::turn = color;
}

bool State::getWhiteKingMoved()
{
	return whiteKingMoved;
}

bool State::getBlackKingMoved()
{
	return blackKingMoved;
}

bool State::getWhiteQRMoved()
{
	return whiteQRMoved;
}

bool State::getWhiteKRMoved()
{
	return whiteKRMoved;
}

bool State::getBlackQRMoved()
{
	return blackQRMoved;
}

bool State::getBlackKRMoved()
{
	return blackKRMoved;
}

void State::giveRawMoves(std::list<Move*>& moves)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			Piece* piece = board[y][x];
			if (piece != nullptr && piece->getColor() == turn)
			{
				piece->genMoves(moves, new Square(y, x), this, turn);
			}
		}
	}

}

void State::giveLegalMoves(std::list<Move*>& moves)
{
	std::list<Move*> newMoves;
	Square kingsSquare;
	State newState = *this;
	newState.giveRawMoves(moves);
	for (auto it = moves.begin(); it != moves.end(); it++)
	{
		newState = *this;
		newState.updateState((*it));
		kingsSquare = findKing(newState.turn);
		newState.setTurn((newState.turn + 1) % 2);
		bool kingThreatened = squareThreatened(kingsSquare, newState.turn);
		if (!kingThreatened)
		{
			newMoves.push_back((*it));
		}
	}
	moves = newMoves;
}

Piece* State::getPiece(int y, int x)
{
	if (board[y][x] == NULL)
	{
		return NULL;
	}
	else;
	{
		return board[y][x];
	}
}

Square State::findKing(int color)
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			Piece* piece = board[y][x];
			if (piece != nullptr && piece->getCode() == Piece::KING && piece->getColor() == color)
			{
				return Square(y, x);
			}
		}
	}
	return Square(-1, -1);
}

bool State::squareThreatened(Square square, std::list<Move*>& moves)
{
	Square* start;
	Square* end;
	for (auto it = moves.begin(); it != moves.end(); it++)
	{
		if ((*it)->isLongCastle())
		{
			State tempState = *this;
			std::list<Move*> rookMoves;
			tempState.playMove((*it));
			Piece* rook = tempState.board[turn == 0 ? 7 : 0][3];
			rook->genMoves(rookMoves, &Square(turn == 0 ? 7 : 0, 3), &tempState, turn);
			for (Move* move : rookMoves)
			{
				start = move->getStartSquare();
				end = move->getEndSquare();
				if (end->getColumn() == square.getColumn() && end->getRow() == square.getRow())
				{
					return true;
				}
			}
		}
		else if ((*it)->isShortCastle())
		{
			State tempState = *this;
			std::list<Move*> rookMoves;
			tempState.playMove((*it));
			Piece* rook = tempState.board[turn == 0 ? 7 : 0][5];
			rook->genMoves(rookMoves, &Square(turn == 0 ? 7 : 0, 5), &tempState, turn);
			for (Move* move : rookMoves)
			{
				start = move->getStartSquare();
				end = move->getEndSquare();
				if (end->getColumn() == square.getColumn() && end->getRow() == square.getRow())
				{
					return true;
				}
			}
		}
		else {
			start = (*it)->getStartSquare();
			end = (*it)->getEndSquare();
			if (end->getColumn() == square.getColumn() && end->getRow() == square.getRow())
			{
				if (!(board[start->getRow()][start->getColumn()]->getCode() == Piece::PAWN
					&& start->getColumn() == end->getColumn()))
				{
					return true;
				}
			}
		}
	}
	return false;
}

bool State::squareThreatened(Square square, int opponent)
{
	std::list<Move*> opponentsMoves;
	//V‰reitt‰in k‰yd‰‰n l‰pi kaikki ruudut ja niiss‰ olevan nappulan siirrot ker‰t‰‰n vastustajan siirtolistaan
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			if (board[y][x] == nullptr) {
				continue;
			}
			if (board[y][x]->getColor() == opponent)
				board[y][x]->genMoves(opponentsMoves, &Square(y, x), this, opponent); // myˆh.sidonta
		}
	}
	// K‰yd‰‰n vastustajaSiirtoLista l‰pi ja jos sielt‰ lˆytyy tarkasteltava ruutu niin tiedet‰‰n sen olevan uhattu
	bool squareOk = true;
	for (auto move : opponentsMoves)
	{
		if (move->isLongCastle())
		{
			State tempState = *this;
			std::list<Move*> rookMoves;
			tempState.playMove(move);
			Piece* rook = tempState.board[opponent == 0 ? 0 : 7][3];
			rook->genMoves(rookMoves, &Square(opponent == 0 ? 0 : 7, 3), &tempState, opponent);
			for (Move* move : rookMoves)
			{
				if (move->getEndSquare()->getColumn() == square.getColumn() && move->getEndSquare()->getRow() == square.getRow())
				{
					return true;
				}
			}
		}
		else if (move->isShortCastle())
		{
			State tempState = *this;
			std::list<Move*> rookMoves;
			tempState.playMove(move);
			Piece* rook = tempState.board[opponent == 0 ? 0 : 7][5];
			rook->genMoves(rookMoves, &Square(opponent == 0 ? 0 : 7, 5), &tempState, opponent);
			for (Move* move : rookMoves)
			{
				if (move->getEndSquare()->getColumn() == square.getColumn() && move->getEndSquare()->getRow() == square.getRow())
				{
					return true;
				}
			}
		}
		else {
			if (square.getColumn() == move->getEndSquare()->getColumn()
				&& square.getRow() == move->getEndSquare()->getRow()) {
				return true;
			}
		}
	}
	return false;
}

double State::evaluate()
{
	double boardValue = 0.0;
	double pieceValue;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (board[y][x] != nullptr)
			{
				switch (board[y][x]->getCode())
				{
				case Piece::PAWN:
					pieceValue = 1.0;
					break;
				case Piece::KNIGHT:
					pieceValue = 3.0;
					break;
				case Piece::BISHOP:
					pieceValue = 3.25;
					break;
				case Piece::ROOK:
					pieceValue = 5.0;
					break;
				case Piece::QUEEN:
					pieceValue = 9.0;
					break;
				default:
					break;
				}
				if (board[y][x]->getColor() == 0)
				{
					boardValue += pieceValue;
				}
				else {
					boardValue -= pieceValue;
				}
			}
		}
	}

	return boardValue;
}

Minimax State::minimax(int depth)
{
	Minimax minimaxValue;

	// Generoidaan aseman lailliset siirrot.
	std::list<Move*> moves;
	giveLegalMoves(moves);

	// Rekursion kantatapaus 1: peli on loppu koska laillisia siirtoja ei ole.
	if (moves.size() == 0)
	{
		minimaxValue.evaluatedValue = endState();
		return minimaxValue;
	}

	// Rekursion kantatapaus 2: katkaisusyvyydess‰
	if (depth == 0)
	{
		minimaxValue.evaluatedValue = evaluate();
		return minimaxValue;
	}

	// Rekursioaskel: kokeillaan jokaista laillista siirtoa s
	// (alustetaan paluuarvo huonoimmaksi mahdolliseksi).
	minimaxValue.evaluatedValue = (turn == 0 ? -1000000 : 1000000);
	for (auto s : moves)
	{
		// Seuraaja-asema (tehd‰‰n nykyisess‰ asemassa siirto s).
		State newState = *this;
		newState.updateState(s);

		// Rekursiivinen kutsu.
		Minimax value = newState.minimax(depth - 1);

		// Tutkitaan ollaan lˆydetty uusi paras siirto.
		if ((turn == 0 && value.evaluatedValue > minimaxValue.evaluatedValue)
			|| (turn == 1 && value.evaluatedValue < minimaxValue.evaluatedValue))
		{
			// Lˆydettiin uusi paras siirto.
			minimaxValue.evaluatedValue = value.evaluatedValue;
			minimaxValue.bestMove = *s;
		}
	}
	return minimaxValue;
}

double State::endState()
{
	// Asemassa ei ole en‰‰ laillisia siirtoja. Etsit‰‰n siirtovuoroisen pelaajan
	// kuningas; jos kuningas on uhattu, on pelaaja h‰vinnyt (muuten tasapeli, "patti").

	// Kuninkaan sijainti (x,y).
	int kx, ky;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (board[y][x] != nullptr && board[y][x]->getCode() == Piece::KING && board[y][x]->getColor() == turn)
			{
				kx = x;
				ky = y;
			}
		}
	}

	if (squareThreatened(Square(kx, ky), turn == 0 ? 1 : 0))
	{
		return 0; // tasapeli (patti)
	}
	else {
		return turn == 0 ? -1000000 : 1000000;	// matti
	}
}

void State::playMove(Move* move)
{
	if (move->isLongCastle())
	{
		if (turn == 0)
		{
			whiteKingMoved = 1;
			whiteQRMoved = 1;
		}
		else {
			blackKingMoved = 1;
			blackQRMoved = 1;
		}
	}
	else if (move->isShortCastle())
	{
		if (turn == 0)
		{
			whiteKingMoved = 1;
			whiteKRMoved = 1;
		}
		else {
			blackKingMoved = 1;
			blackKRMoved = 1;
		}
	}
	else {
		Piece* piece = board[move->getStartSquare()->getRow()][move->getStartSquare()->getColumn()];
		if (piece->getCode() == Piece::PAWN && abs(move->getEndSquare()->getRow() - move->getStartSquare()->getRow()) > 1)
		{
			doubleStepOnColumn = move->getEndSquare()->getColumn();
		}
		else {
			doubleStepOnColumn = -1;
		}
		if (piece->getCode() == Piece::KING)
		{
			switch (piece->getColor())
			{
			case 0:
				whiteKingMoved = 1;
				break;
			case 1:
				blackKingMoved = 1;
				break;
			}
		}
		if (piece->getCode() == Piece::ROOK)
		{
			switch (piece->getColor())
			{
			case 0:
				switch (move->getStartSquare()->getColumn())
				{
				case 0:
					whiteQRMoved = 1;
					break;
				case 7:
					whiteKRMoved = 1;
					break;
				default:
					break;
				}
				break;
			case 1:
				switch (move->getStartSquare()->getColumn())
				{
				case 0:
					blackQRMoved = 1;
					break;
				case 7:
					blackKRMoved = 1;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
		}
	}
	updateState(move);
}

bool State::moveIsLegal(Move* move)
{
	Square* start = move->getStartSquare();
	Square* end = move->getEndSquare();
	if (start->getRow() < 0 || start->getRow() > 7 || start->getColumn() < 0 || start->getColumn() > 7
		|| end->getRow() < 0 || end->getRow() > 7 || end->getColumn() < 0 || end->getColumn() > 7)
	{
		return false;
	}
	if (board[start->getRow()][start->getColumn()] == nullptr)
	{
		return false;
	}
	Piece* piece = board[start->getRow()][start->getColumn()];
	std::list<Move*> moves;
	piece->genMoves(moves, start, this, turn);
	for (auto it = moves.begin(); it != moves.end(); it++)
	{
		if ((*it)->getEndSquare()->getRow() == end->getRow() && (*it)->getEndSquare()->getColumn() == end->getColumn())
		{
			return true;
		}
	}
	return false;
}