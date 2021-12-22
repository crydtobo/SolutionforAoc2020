/*
 * Declaration.h
 *
 *  Created on: Feb 23, 2021
 *      Author: dawid
 */
#ifndef INCLUDE_DECLARATION_H_
#define INCLUDE_DECLARATION_H_

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <array>

class Declaration
{
public:
	Declaration() {
		sum = 0;
	}
	
	std::vector<char> letter;
	void generateQuestion();
	int compared(std::string input);
	int comparedSecond(std::vector<std::string> input);
	void check(std::vector<std::string> input);
	void checkSecond(std::vector<std::vector<std::string>> input);
	int sum{0};

private:
	int countLetterOccur(const char &letter, const std::string &input);
};

std::vector<std::string> parseFile(std::fstream &file);
std::vector<std::vector<std::string>> parseFile2(std::fstream &file);

#endif /* INCLUDE_DECLARATION_H_ */