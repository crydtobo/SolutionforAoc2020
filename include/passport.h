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
		parse_to_task(std::move(file));
	}

	void parse_to_task(std::string &&input);
	void parse_kv(std::string &&input);
	bool check();
	bool check_hgt();
	bool check_hcl();
	bool check_ecl();
	bool check_pid();
	bool is_valid();

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

std::vector<std::string> decode_input(std::fstream &file);
std::vector<Passport> parse_input_from_file(std::fstream &file);

#endif  /* INCLUDE_PASSPORT_H_*/