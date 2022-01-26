/*
 * bags.h
 *
 *  Created on: Feb 25, 2021
 *      Author: dawid
 */
#ifndef INCLUDE_BAGS_H_
#define INCLUDE_BAGS_H_

#include <vector>
#include <string>
#include <map>
#include <regex>
#include <cassert>
#include <deque>
#include <unordered_set>
#include <unordered_map>

class Bags
{
public:
	using contained_t = std::unordered_map<std::string, std::unordered_set<std::string>>;
	using contains_t = std::unordered_map<std::string, std::unordered_map<std::string, uint32_t>>;

	Bags() = default;

	uint32_t countBags(contains_t &contains, std::string bagName);
	void createContainer(const std::string &in);
	void checkIfBagsExist(std::sregex_iterator &i, std::smatch &result);
	void checkIfNameExist(const std::string &in, std::smatch &result);
	std::tuple<std::sregex_iterator, std::sregex_iterator> demandOfSearching(const std::string &in);
	void parseInput(std::vector<std::string> &in);
	
	contained_t &contained;
	contains_t &contains;
};

#endif /* INCLUDE_BAGS_H_ */