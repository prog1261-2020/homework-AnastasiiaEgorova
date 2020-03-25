#include "Player.h"

Player::Player() {
	piece = ' ';
}

Player::Player(char p) {
	piece = p;
}

Player::~Player() {
	delete this;
}

char Player::getPiece() {					//returns player's piece
	return piece;
}
