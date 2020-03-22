/**
* Board.h
* TicTacToe
*
* Created by Anastasiia Egorova on 2020-03-22
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Declaration of Board functions and fields
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
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

class Board
{
public:
	Board();
	void reset();
	bool isFull() const;
	bool isValidMove(int move) const;
	bool isWinner(char playerPiece) const;
	std::string getBoardPlaces() const;
	std::string getCurrentBoard() const;
	void makeMove(char playerPiece, int move);

private:
	//bool checkCombo(int combo, char piece);

	static const int NUM_SQUARES = 9;										//total number of squares
	static const char EMPTY = ' ';											//empty strings
	static const int NUM_WINNING_COMBOS = 8;								//number of winning combos
	static const int NUM_IN_COMBO = 3;										//number of items in combo
	static const int WINNING_COMBOS[NUM_WINNING_COMBOS][NUM_IN_COMBO];		//matrix of winning combos

	std::vector<char> board;												//'X', 'O', or ' '
};

