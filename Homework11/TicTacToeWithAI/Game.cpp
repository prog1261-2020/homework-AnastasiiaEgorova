#include "Game.h"

Game::Game(Player* one, Player* two, Board* b) {
	players[FIRST] = one;
	players[SECOND] = two;
	board = b;
}

bool Game::isPlaying() const {											//checks if there is a winner or board is full
	return (!isTie() && !board->isWinner('X') && !board->isWinner('O'));
}

bool Game::isTie() const {												//checks if the board is full
	return board->isFull();
}

std::string Game::getInstructions() const {								//prints out the instructions
	std::stringstream ss;

	ss << "Welcome to Tic Tac Toe Game!\n\n";
	ss << "First player is X. Second player is O.\n";
	ss << "Make a move after each other\n";
	ss << "The first person with their marks 3 in a row (up, down, across, or diagonally), wins!\n\n";

	return ss.str();
}

void Game::nextPlayer() {												//change the player
	currentPlayer = (currentPlayer + 1) % NUM_PLAYERS;
}

std::string Game::getAnnounceResult() const {							//prints out the result
	std::stringstream ss;
	if (isTie()) {
		ss << "There is no winner :(\n\n";
	}
	else {
		ss << "And the winner is: " << players[(currentPlayer + 1) % NUM_PLAYERS]->getPiece() << "!!!\n\n";
	}
	return ss.str();
}

void Game::play() {														//the play itself
	currentPlayer = FIRST;

	while (isPlaying()) {												//while is not tied, or there is no winner
		system("cls");
		std::cout << getInstructions();
		std::cout << board->getBoardPlaces() << "\n\n";
		std::cout << board->getCurrentBoard() << "\n\n";
		std::cout << "Current player is: " << players[currentPlayer]->getPiece() << "\nYour move: ";

		int move = players[currentPlayer]->getMove();
		while (!board->isValidMove(move)) {								//checks if move is ok
			std::cout << "Please enter a valid number: ";
			move = players[currentPlayer]->getMove();
		}

		board->makeMove(players[currentPlayer]->getPiece(), move);		//makes that move on the board

		nextPlayer();													//switches to next player
	}

	system("cls");
	std::cout << getInstructions();
	std::cout << board->getBoardPlaces() << "\n\n";
	std::cout << board->getCurrentBoard() << "\n\n";
	std::cout << getAnnounceResult();									//announces the result
}
