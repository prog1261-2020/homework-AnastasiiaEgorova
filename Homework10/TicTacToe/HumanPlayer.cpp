/**
* HumanPlayer.cpp
* TicTacToe
*
* Created by Anastasiia Egorova on 2020-03-22
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Initialization of HumanPlayer functions
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

#include "HumanPlayer.h"

HumanPlayer::~HumanPlayer() {			//D-TOR
	delete this;
}

int HumanPlayer::makeMove() {			//still not using
	int move;
	std::cin >> move;

	return move;
}