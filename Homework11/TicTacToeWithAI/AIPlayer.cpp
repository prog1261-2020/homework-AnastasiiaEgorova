/**
* AIPlayer.cpp
* TicTacToe
*
* Created by Anastasiia Egorova on 2020-03-25
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Implementation of AIPlayer functions
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

#include "AIPlayer.h"

AIPlayer::AIPlayer(char p, Board* b) : Player(p) {
	board = b;
}

int AIPlayer::getMove() {
	int move;
	char opponentPiece;

	if (getPiece() == 'X')
		opponentPiece = 'O';
	else
		opponentPiece = 'X';

	//first checks is the next move can be winning
	/*move = thirdInRow(getPiece());
	if (move != -1)
		return move;*/

	for (int i = 0; i < board->NUM_WINNING_COMBOS; ++i) {						//first: check if there are two filled cells in a row 
		int numInCombo = 0;
		int coords[2];
		for (int j = 0; j < board->NUM_IN_COMBO; ++j) {
			if (board->getBoard()[board->WINNING_COMBOS[i][j]] == getPiece()) {
				++numInCombo;
			}
		}
		if (numInCombo == 2) {													//second: check if the third one is empty -> make a move there
			for (int j = 0; j < board->NUM_IN_COMBO; ++j) {
				if (board->getBoard()[board->WINNING_COMBOS[i][j]] == ' ') {
					move = board->WINNING_COMBOS[i][j];
					return move;
				}
			}
		}
	}


	//second checks if the next move od opponent can not be winning
	/*move = thirdInRow(opponentPiece);
	if (move != -1)
		return move;*/
	for (int i = 0; i < board->NUM_WINNING_COMBOS; ++i) {						//first: check if there are two filled cells in a row 
		int numInCombo = 0;
		int coords[2];
		for (int j = 0; j < board->NUM_IN_COMBO; ++j) {
			if (board->getBoard()[board->WINNING_COMBOS[i][j]] == opponentPiece) {
				++numInCombo;
			}
		}
		if (numInCombo == 2) {													//second: check if the third one is empty -> make a move there
			for (int j = 0; j < board->NUM_IN_COMBO; ++j) {
				if (board->getBoard()[board->WINNING_COMBOS[i][j]] == ' ') {
					move = board->WINNING_COMBOS[i][j];
					return move;
				}
			}
		}
	}

	//else
	if (getPiece() == 'O' && board->getBoard()[4] == ' ') {						//if player is 'O' => taking the center
		move = 4;
		return move;
	}

	if (getPiece() == 'X') {													//if player is 'X' => taking corners
		if (board->getBoard()[0] == ' ') {
			move = 0;
			return move;
		}
		else if (board->getBoard()[8] == ' ') {
			move = 8; 
			return move;
		}
		else if (board->getBoard()[2] == ' ') {
			move = 2;
			return move;
		}
		else if (board->getBoard()[6] == ' ') {
			move = 6;
			return move;
		}
	}

	for (int i = 0; i < 9; ++i) {
		if (board->isValidMove(i)) {
			move = i;
			break;
		}
	}

	return move;
}

//int AIPlayer::thirdInRow(char piece) {
//	int move = -1;														//two iterations: 
//
//	for (int i = 0; i < board->NUM_WINNING_COMBOS; ++i) {						//first: check if there are two filled cells in a row 
//		int numInCombo = 0;												
//		int coords[2];													
//		for (int j = 0; j < board->NUM_IN_COMBO; ++j) {						
//			if (board->getBoard()[board->WINNING_COMBOS[i][j]] == piece) {		
//				++numInCombo;											
//			}
//		}
//		if (numInCombo == 2) {											//second: check if the third one is empty -> make a move there
//			for (int j = 0; j < board->NUM_IN_COMBO; ++j) {					
//				if (board->getBoard()[board->WINNING_COMBOS[i][j]] == ' ') {
//					move = board->WINNING_COMBOS[i][j];
//					return move;
//				}
//			}
//		}
//	}
//	return move;
//}

