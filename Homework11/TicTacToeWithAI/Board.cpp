#include "Board.h"

Board::Board() {													//C-TOR
	reset();
}

std::vector<char> Board::getBoard() {
	return board;
}

void Board::reset() {												//resets the board. currently not using
	board = std::vector<char>(9, ' ');
}

bool Board::isFull() const {										//checks if the board is full with fancy algorithm
	return std::none_of(board.begin(), board.end(), [](char e) {return e == EMPTY; });
}

bool Board::isValidMove(int move) const {							//checks if move is within the range, and the cell is empty
	if (move >= 0 && move < NUM_SQUARES)
		return (board[move] == EMPTY);
	else
		return false;
}

bool Board::checkCombo(int combo, char piece) const {
	int piecesInCombo = 0;
	for (int i = 0; i < NUM_IN_COMBO; ++i) {
		if (board[WINNING_COMBOS[combo][i]] == piece) {
			++piecesInCombo;
		}
	}
	if (piecesInCombo == NUM_IN_COMBO)
		return true;
	else
		return false;
}

bool Board::isWinner(char piece) const {						//checks if parameter is winner
	bool winner = false;
	int combo = 0;
	while (!winner && combo < NUM_WINNING_COMBOS) {
		winner = checkCombo(combo, piece);
		++combo;
	}
	return winner;
}

std::string Board::getBoardPlaces() const {							//prints out the board places
	std::stringstream ss;

	ss << " 0 | 1 | 2\n";
	ss << "-----------\n";
	ss << " 3 | 4 | 5\n";
	ss << "-----------\n";
	ss << " 6 | 7 | 8\n";

	return ss.str();
}

std::string Board::getCurrentBoard() const {						//prints out the current board
	std::stringstream ss;

	ss << " " << board[0] << " | " << board[1] << " | " << board[2] << "\n";
	ss << "-----------\n";
	ss << " " << board[3] << " | " << board[4] << " | " << board[5] << "\n";
	ss << "-----------\n";
	ss << " " << board[6] << " | " << board[7] << " | " << board[8] << "\n";

	return ss.str();
}

void Board::makeMove(char playerPiece, int move) {					//save move to the board
	board[move] = playerPiece;
}

const int Board::WINNING_COMBOS[NUM_WINNING_COMBOS][NUM_IN_COMBO] = {			//all winning combos
	{0, 1, 2},
	{3, 4, 5},
	{6, 7, 8},
	{0, 3, 6},
	{1, 4, 7},
	{2, 5, 8},
	{0, 4, 8},
	{2, 4, 6}
};
