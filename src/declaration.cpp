/*
 * Declaration.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: dawid
 */

#include "../include/declaration.h"

#define ALFABET_LETTERS 26

void Declaration ::generateQuestion()
{
	for (int i = 97; i <= 122; i++)
	{
		letter.push_back(static_cast<char>(i));
	}
}

int Declaration::countLetterOccur(const char &letter, const std::string &input){
	auto found = std::find(input.begin(), input.end(), letter);
	if(found != input.end()){
		return 1;
	}
	return 0;
}

int Declaration ::compared(std::string input)
{
	int count = 0;
	for (auto j : letter)
	{
		count += countLetterOccur(j,input);
	}
	return count;
}

void countFrequency(const std::string &i, std::array<int, ALFABET_LETTERS> &q)
{
	for (auto ch : i)
	{
		q[ch - 'a']++;
	}
}

int countTheSame(std::size_t &i, std::size_t &&sizeOfDeclaration)
{
		return (i == sizeOfDeclaration) ? 1 : 0;
}

int Declaration ::comparedSecond(std::vector<std::string> input)
{
	int count = 0;
	std::array<int, ALFABET_LETTERS> q = {};

	for (auto i : input)
	{
		countFrequency(i, q);
	}

	for (std::size_t i : q)
	{
		count += countTheSame(i, input.size());
	}
	
	return count;
}

void Declaration ::check(std::vector<std::string> input)
{
	int count = 0;
	generateQuestion();
	for (auto i : input)
	{
		count = compared(i);
		sum += count;
	}
}

void Declaration ::checkSecond(std::vector<std::vector<std::string>> input)
{
	int count = 0;
	generateQuestion();
	for (auto i : input)
	{
		count = comparedSecond(i);
		sum += count;
	}
}

std::vector<std::string> parseFile(std::fstream &file)
{
	std::string line, passport = "";
	std::vector<std::string> passport_data;
	while (getline(file, line))
	{
		if (!line.empty())
		{
			passport += line + " ";
		}
		else
		{
			passport_data.emplace_back(std::move(passport));
			passport = "";
		}
	}
	passport_data.emplace_back(std::move(passport));
	return passport_data;
}

std::vector<std::vector<std::string>> parseFile2(std::fstream &file)
{
	std::string line;
	std::vector<std::vector<std::string>> dec;
	std::vector<std::string> group;
	while (getline(file, line))
	{
		if (!line.empty())
		{
			group.push_back(line);
		}
		else
		{
			dec.push_back(group);
			group.clear();
		}
	}
	dec.push_back(group);
	return dec;
}