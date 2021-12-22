#ifndef INCLUDE_PASSPORT_H_
#define INCLUDE_PASSPORT_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <array>
#include <iterator>

class Passport
{
public:
	Passport(std::string &&file) : byr(-1), iyr(-1), eyr(-1)
	{
		parseToTask(std::move(file));
	}

	void parseToTask(std::string &&input);
	void parseKey(std::string &&input);
	bool check();
	bool checkHgt();
	bool checkHcl();
	bool checkEcl();
	bool checkPid();
	bool isValid();

private:
	std::string cid;
	int byr;
	int iyr;
	int eyr;
	std::string hgt;
	std::string hcl;
	std::string ecl;
	std::string pid;
};

std::vector<std::string> decodeInput(std::fstream &file);
std::vector<Passport> parseInputFromFile(std::fstream &file);

#endif  /* INCLUDE_PASSPORT_H_*/