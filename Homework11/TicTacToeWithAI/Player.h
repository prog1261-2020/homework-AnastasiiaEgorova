#pragma once
#include <iostream>

class Player
{
public:
	Player();
	Player(char p);
	virtual ~Player();

	char getPiece();
	virtual int getMove() = 0;

private:
	char piece;
};

