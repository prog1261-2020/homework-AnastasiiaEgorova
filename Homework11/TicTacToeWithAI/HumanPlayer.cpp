#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(char p) : Player(p)
{}

HumanPlayer::~HumanPlayer() {			//D-TOR
	delete this;
}

int HumanPlayer::getValidInput() {
	int m;
	std::cin >> m;
	while (std::cin.fail()) {			//checks if move is ok
		std::cin.clear();
		std::cin.ignore(32767, '\n');
		std::cout << "Please enter a valid number: ";
		std::cin >> m;
	}
	return m;
}

int HumanPlayer::getMove() {
	int move = getValidInput();
	return move;
}
