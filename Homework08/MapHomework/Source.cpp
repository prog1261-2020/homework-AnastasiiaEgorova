/**
* Source.cpp
* MapHomework
*
* Created by Anastasiia Egorova on 2020-03-11
*
* I certify that this work is solely my own and complies with
* NBCC Academic Integrity Policy (policy 1111)
*
* DESCRIPTION
* main() function for Map Homework
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
#include <map>

int main() {
	std::ifstream file;														//opens the file
	file.open("fox.txt");

	if (file.fail()) {
		std::cerr << "Cannot open the file.\n";
		exit(1);
	}

	std::map<std::string, int> m;											//creates map m

	while (!file.eof()) {													//while ! the end of the file
		std::string line;					
		std::getline(file, line, '\n');										//gets text line by line

		while (!line.empty()) {
			std::string word;	
			std::getline((std::stringstream)line, word, ' ');				//gets each word within the line

			for (int i = 0; i < word.length(); ++i)							//lowercases each letter in a word
				word[i] = tolower(word[i]);

			line.erase(0, word.length()+1);									//erase the word from the line

			while (!word.empty() && ispunct(word.back()))					//deletes all puncts from back
					word.pop_back();

			while (!word.empty() && ispunct(word[0]))						//deletes all puncts from beginning
				word.erase(0, 1);

			if (!word.empty()) {											
				if (m.find(word) == m.end())								//if word does not exist in the m
					m.insert(std::pair<std::string, int>(word, 1));			//adds it to m
				else
					m[word]++;												//otherwise, increments int for the element with the same key
			}
		}
	}

	for (auto p : m) {
		std::cout << p.first << ": " << p.second << std::endl;				//prints m to the screen
	}

	file.close();
}