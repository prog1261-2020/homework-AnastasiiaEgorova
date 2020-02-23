/**
* Question.cpp
* QuizHomework
*
* Created by Anastasiia Egorova on 2020-02-23
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* Implementation o 
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

#include "Question.h"

Question::Question(std::ifstream& theFile) {
	const int numberOfAnswers = 4;
	std::string strHelper;
															//for a question
	do														//checks if the line is not empty
	{
		std::getline(theFile, question);
	} while (question == "\r");
															//for all options
	for (int i = 0; i < numberOfAnswers; ++i) {				//for each element in a vector of answers
		do													//checks if the line is not empty
		{
			std::getline(theFile, strHelper);
		} while (strHelper == "\r");
		answers.push_back(strHelper);
	}
															//for the answer
	do														//checks if the line is not empty
	{
		std::getline(theFile, strHelper);
	} while (strHelper == "\r");
	std::istringstream ss(strHelper);
	ss >> correct;
}

std::string Question::printQuestion() const {

	std::stringstream ss;									//creates stringstream

	ss << this->question << "\n";							//prints out the question

	for (int i = 0; i < 4; ++i) {							//prints out all the answers
		ss << i + 1 << ") " << this->answers[i] << "\n";
	}

	ss << "\nPlease choose 1-4" << std::endl;

	return ss.str();
}
