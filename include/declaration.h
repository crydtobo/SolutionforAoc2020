/*
 * Declaration.h
 *
 *  Created on: Feb 23, 2021
 *      Author: dawid
 */

#ifndef INCLUDE_DECLARATION_H_
#define INCLUDE_DECLARATION_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

class Declaration{
public:
	Declaration() = default;
	std::vector<char> letter;
	void generate_question();
	int compared(std::string input);
	int compared_second(std::vector<std::string> input);
	void check(std::vector<std::string> input);
	void check_second(std::vector<std::vector<std::string>> input);
	int sum{0};

};

std::vector<std::string> parse_file(std::fstream &file);
std::vector<std::vector<std::string>> parse_file2(std::fstream &file);

#endif /* INCLUDE_DECLARATION_H_ */