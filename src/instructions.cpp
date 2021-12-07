/*
 * Instructions.cpp
 *
 *  Created on: May 12, 2021
 *      Author: dawid
 */
#include "../include/instruction.h"

Instruction::Instruction() : acc{0}, posisition{1}, remember{0}{
}

void Instruction::reading_instructions(std::vector<std::string> input){
	remember = posisition;
	//for(auto i: input){
		//auto parse = parseInstruct(i);
	//}
}

void Instruction::doJmp(std::vector<std::string> input){
		std::cout<<"GRUU";

}

Instruction::instruct parseInstruct(std::string &input){
	std::stringstream s(input);
	std::string div;
	std::vector<std::string> l;
	Instruction::instruct num;

	//num.push_back(std::make_pair( l[0], std::stoi(l[1]) ) );
	return num;
}
