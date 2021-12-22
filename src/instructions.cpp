/*
 * Instructions.cpp
 *
 *  Created on: May 12, 2021
 *      Author: dawid
 */
#include "../include/instruction.h"

Instruction::Instruction() : acc{0}, posisition{1}, remember{0}
{
}

void Instruction::readingInstructions(std::vector<std::string> input)
{
	remember = posisition;
}

void Instruction::doJmp(std::vector<std::string> input)
{
	auto found = std::find(input.begin(), input.end(), "dojmp");
}

Instruction::instruct parseInstruct(std::string &input)
{
	std::stringstream s(input);
	std::string div;
	std::vector<std::string> l;
	Instruction::instruct num;

	return num;
}
