#pragma once
#include <iostream>
#include "Player.h"

class HumanPlayer : public Player
{
public:
	HumanPlayer(char p);
	virtual ~HumanPlayer() override;		//D-TOR

	int getValidInput();
	int getMove() override;				//is not using for now
};

