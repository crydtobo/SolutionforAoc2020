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

std::tuple<std::sregex_iterator, std::sregex_iterator>  Bags::demandOfSearching(const std::string &in)
{
	std::regex numberOfBags(R"(,? (\d+) (\w+ \w+) bags?)");
	auto start = std::sregex_iterator(in.begin(), in.end(), numberOfBags);
	auto end = std::sregex_iterator();
	return {start,end};
}

void Bags::checkIfNameExist(const std::string &in, std::smatch &result)
{
	std::regex nameOfBags(R"((\w+ \w+) bags contain)");
	assert(std::regex_search(in, result, nameOfBags));
}

void Bags::checkIfBagsExist(std::sregex_iterator &i, std::smatch &result)
{
	std::smatch match = *i;
	contains[result[1]].emplace(match[2], std::stoi(match[1]));

	if (!contained.emplace(match[2], std::unordered_set<std::string>({result[1]})).second)
	{
		contained[match[2]].insert(result[1]);
	}
}

void Bags::createContainer(const std::string &in)
{
		std::smatch result;
		checkIfNameExist(in,result);
		contains.emplace(result[1], std::unordered_map<std::string, uint32_t>());

		auto [start, end] = demandOfSearching(in);
		for (std::sregex_iterator i = start; i != end; ++i)
		{
			checkIfBagsExist(i, result);
		}
}

void Bags::parseInput(std::vector<std::string> &input)
{
	for (auto in : input)
	{
		createContainer(in);
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