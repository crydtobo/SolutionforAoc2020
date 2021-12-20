/*
 * Instruction.h
 *
 *  Created on: May 12, 2021
 *      Author: dawid
 */
#ifndef INCLUDE_INSTRUCTION_H_
#define INCLUDE_INSTRUCTION_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <iostream>

class Instruction
{
public:
	using instruct = std::vector<std::pair<std::string, int>>;

	Instruction();
	void reading_instructions(std::vector<std::string> input);
	instruct parseInstruct(std::string &input);
	void doJmp(std::vector<std::string> m);

private:
	int acc;
	int posisition{0};
	int remember{0};
};

#endif /* INCLUDE_INSTRUCTION_H_ */