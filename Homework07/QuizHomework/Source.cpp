/**
* Source.cpp
* QuizHomework
*
* Created by Anastasiia Egorova on 2020-02-23
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Main function for Quiz Homework Project
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

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include "Question.h"

int main(int argc, char* argv[]) {

	std::ifstream theFile;								//creates the ifstream
	theFile.open("file.txt", std::ios::binary);			//opens the file

	if (theFile.fail()) {
		std::cerr << "File not opened\n";
		exit(1);
	}

	std::vector<Question> trivia;						//creates vector of questions

	while (!theFile.eof()) {							//while theFile is not ended, adds questions to the vector
		Question question(theFile);
		trivia.push_back(question);
	}

	theFile.close();									//closes the file

	std::cout << "Let\'s play a game!\n";
	std::cout << "Please answer all the questions.\n\n";
	Sleep(2000);

	int i = 0;											//just an iterator
	int rightAnswers = 0;								//number of right answers
	int userAnswer;									

	while (i < trivia.size()) {							//while the vector is not ended

		system("cls");
		std::cout << "Question " << i + 1 << " out of " << trivia.size() << " :\n\n";
		std::cout << trivia[i].printQuestion();

		std::cin >> userAnswer;

		if (userAnswer == trivia[i].correct + 1) {		//checks if the answer is correct
			rightAnswers++;
			std::cout << "Correct!\n";
		}
		else {
			std::cout << "Incorrect.\n";
		}

		i++;

		Sleep(1500);
	}

	std::cout << "\n\nCongrats! You answered " << rightAnswers << " questions correct! \n\n";
} 