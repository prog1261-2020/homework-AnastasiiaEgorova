#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "HumanPlayer.h"
#include "Board.h"

class Game
{
public:
	Game();																		//NO ARGS C-TOR
	Game(Player*, Player*, Board*);												//dependency injenction
	bool isPlaying() const;
	bool isTie() const;
	std::string getInstructions() const;
	void nextPlayer();
	std::string getAnnounceResult() const;
	void play();

private:
	static const int NUM_PLAYERS = 2;											//total number of players in the game
	static const int FIRST = 0;													//first player
	static const int SECOND = 1;												//second player

	Board* board;																//board
	Player* players[NUM_PLAYERS];												//array of players (pointers because it'll be polymorphic)
	int currentPlayer;															//current player that switch from each move
};


