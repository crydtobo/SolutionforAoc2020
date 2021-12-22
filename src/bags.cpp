/*
 * Bags.cpp
 *
 *  Created on: Feb 25, 2021
 *      Author: dawid
 */
#include "../include/bags.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void Bags::parseInput(std::vector<std::string> &input, contained_t &contained, contains_t &contains)
{
	std::regex nameOfBags(R"((\w+ \w+) bags contain)");
	std::regex numberOfBags(R"(,? (\d+) (\w+ \w+) bags?)");
	std::string line;
	for (auto in : input)
	{
		std::smatch result;
		assert(std::regex_search(in, result, nameOfBags));
		contains.emplace(result[1], std::unordered_map<std::string, uint32_t>());
		auto start = std::sregex_iterator(in.begin(), in.end(), numberOfBags);
		auto end = std::sregex_iterator();
		for (std::sregex_iterator i = start; i != end; ++i)
		{
			std::smatch match = *i;
			contains[result[1]].emplace(match[2], std::stoi(match[1]));

			if (!contained.emplace(match[2], std::unordered_set<std::string>({result[1]})).second)
			{
				contained[match[2]].insert(result[1]);
			}
		}
	}
}

uint32_t Bags::countBags(contains_t &contains, std::string bagName)
{
	uint32_t bagCount{0};
	for (auto &bag : contains[bagName])
	{
		bagCount += bag.second + (bag.second * countBags(contains, bag.first));
	}
	return bagCount;
}