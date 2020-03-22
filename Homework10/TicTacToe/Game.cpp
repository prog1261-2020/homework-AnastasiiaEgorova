/**
* Game.cpp
* TicTacToe
*
* Created by Anastasiia Egorova on 2020-03-22
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Initialization of Game functions
*
*  Copyright 2020
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*
*/

#include "Game.h"

Game::Game() {
	Board board;														//initialize the board

	players[0] = new HumanPlayer();										//first player
	players[1] = new HumanPlayer();										//second player

	currentPlayer = FIRST;												//current player is first by default
}

bool Game::isPlaying() const {											//checks if there is a winner or board is full
	return (!isTie() && !board.isWinner('X') && !board.isWinner('O'));	
}

bool Game::isTie() const {												//checks if the board is full
	return board.isFull();
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

	players[FIRST]->setPiece('X');
	players[SECOND]->setPiece('O');

	while (isPlaying()) {												//while is not tied, or there is no winner
		system("cls");
		std::cout << getInstructions();
		std::cout << board.getBoardPlaces() << "\n\n";
		std::cout << board.getCurrentBoard() << "\n\n";
		std::cout << "Current player is: " << players[currentPlayer]->getPiece() << "\nYour move: ";

		int move;
		std::cin >> move;
		while (std::cin.fail() || !board.isValidMove(move)) {			//checks if move is ok
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Please enter a valid number: ";
			std::cin >> move;
		}
		
		board.makeMove(players[currentPlayer]->getPiece(), move);		//makes that move on the board

		nextPlayer();													//switches to next player
	}

	system("cls");
	std::cout << getInstructions();
	std::cout << board.getBoardPlaces() << "\n\n";
	std::cout << board.getCurrentBoard() << "\n\n";
	std::cout << getAnnounceResult();									//announces the result
}
