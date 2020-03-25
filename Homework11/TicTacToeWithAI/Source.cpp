#include <iostream>
#include <string>

#include "Game.h"
#include "HumanPlayer.h"
#include "Board.h"
#include "AIPlayer.h"


int main() {
	auto board = new Board();
	Player* two = new HumanPlayer('O');
	Player* one = new AIPlayer('X', board);

	Game game(one, two, board);				//but better to pass vector, not two players
	game.play();							//play the game
}