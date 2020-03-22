/**
* Game.h
* TicTacToe
*
* Created by Anastasiia Egorova on 2020-03-22
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Declaration of Game functions and fields
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

	Board board;																//board
	Player* players[NUM_PLAYERS];												//array of players (pointers because it'll be polymorphic)
	int currentPlayer;															//current player that switch from each move
};

