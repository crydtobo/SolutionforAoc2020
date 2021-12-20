/*
 * Declaration.cpp
 *
 *  Created on: Feb 23, 2021
 *      Author: dawid
 */

#include "../include/declaration.h"

void Declaration ::generate_question()
{
	for (int i = 97; i <= 122; i++)
	{
		letter.push_back(static_cast<char>(i));
	}
}
int Declaration ::compared(std::string input)
{
	int count = 0;
	for (auto j : letter)
	{
		for (size_t i = 0; i < input.size(); i++)
		{
			if (input[i] == j)
			{
				count++;
				break;
			}
		}
	}
	return count;
}

int Declaration ::compared_second(std::vector<std::string> input)
{
	int count = 0;
	int q[26] = {};
	for (auto i : input)
	{
		for (auto ch : i)
		{
			q[ch - 'a']++;
		}
	}
	for (size_t i : q)
	{
		if (i == input.size())
		{
			count++;
		}
	}
	return count;
}

void Declaration ::check(std::vector<std::string> input)
{
	int count = 0;
	generate_question();
	for (auto i : input)
	{
		count = compared(i);
		sum += count;
	}
}

void Declaration ::check_second(std::vector<std::vector<std::string>> input)
{
	int count = 0;
	generate_question();
	for (auto i : input)
	{
		count = compared_second(i);
		sum += count;
	}
}

std::vector<std::string> parse_file(std::fstream &file)
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

std::vector<std::vector<std::string>> parse_file2(std::fstream &file)
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