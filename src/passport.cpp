/*
 * passport.cpp
 *
 *  Created on: Feb 4, 2021
 *      Author: dawid
 */
#include <regex>

#include "../include/passport.h"

std::vector<Passport> parse_input_from_file(std::fstream &file)
{
	std::string line, passport = "";
	std::vector<Passport> passport_data;
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

void Passport::parse_kv(std::string &&input)
{
	std::string key = input.substr(0, 3);
	std::string value = input.substr(4, std::string::npos);
	if (key == "byr")
	{
		byr = std::stoi(value);
	}
	else if (key == "iyr")
	{
		iyr = std::stoi(value);
	}
	else if (key == "eyr")
	{
		eyr = std::stoi(value);
	}
	else if (key == "hgt")
	{
		hgt = value;
	}
	else if (key == "hcl")
	{
		hcl = value;
	}
	else if (key == "ecl")
	{
		ecl = value;
	}
	else if (key == "pid")
	{
		pid = value;
	}
	else if (key == "cid")
	{
		cid = value;
	}
	else
	{
		std::cout << "unknown key" << std::endl;
	}
}

void Passport::parse_to_task(std::string &&input)
{
	size_t len = input.find(" ");
	while (len != std::string::npos)
	{
		parse_kv(input.substr(0, len));
		input.erase(0, len + 1);
		len = input.find(" ");
	}
}

bool isCorrectHgtForCm(const int &value){
	if(value >= 150 and value <= 193)
		return true;
	return false;
}

bool isCorrectHgtForIn(const int &value){
	if(value >= 59 and value <= 76)
		return true;
	return false;
}

bool isCorrectHgtForSizeBiggerThanThree(const std::string &hgt)
{
	int value;
	std::string hgt_t, unit;

	unit = hgt.substr(hgt.size() - 2, hgt.size());
	hgt_t = hgt.substr(0, hgt.size() - 2);
	value = std::stoi(hgt_t);

	if (unit == "cm")
	{
		return isCorrectHgtForCm(value);
	}
	else if (unit == "in")
	{
		return isCorrectHgtForIn(value);
	}
	else {
		return false;
	}
}

bool Passport::check_hgt()
{
	if (hgt.size() > 3)
	{
		return isCorrectHgtForSizeBiggerThanThree(hgt);
	}
	return false;
}

bool Passport::check_hcl()
{
	bool h1 = false;
	std::string unit = hcl.substr(0, hcl.size());
	const std::regex pattern("^#[0-9a-f]+");
	if (std::regex_match(unit, pattern))
	{
		h1 = true;
	}
	else
	{
		h1 = false;
	}
	return h1;
}

bool Passport::check_ecl()
{
	bool h1 = false;
	std::string unit = ecl.substr(0, ecl.size());
	std::vector<std::string> field{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
	for (auto i : field)
	{
		if (i.compare(unit) == 0)
		{
			h1 = true;
			break;
		}
		else
		{
			h1 = false;
		}
	}
	return h1;
}

bool Passport::check_pid()
{
	bool h1 = false;
	std::string first = pid.substr(0, 1);
	if (pid.size() == 9)
	{
		h1 = true;
	}
	else
	{
		h1 = false;
	}
	return h1;
}
bool Passport::check()
{
	bool b = false;
	bool b1 = (byr >= 1920 and byr <= 2002);
	bool b2 = (iyr >= 2010 and iyr <= 2020);
	bool b3 = (eyr >= 2020 and eyr <= 2030);
	bool b4 = check_hgt();
	bool b5 = check_hcl();
	bool b6 = check_ecl();
	bool b7 = check_pid();
	b = b1 and b2 and b3 and b4 and b5 and b6 and b7;
	return b;
}

bool Passport ::is_valid()
{
	bool f = false;
	f = ((byr != -1) and (iyr != -1) and (eyr != -1) and (hgt != "") and (hcl != "") and (ecl != "") and (pid != ""));
	if (f == 0)
	{
		return false;
	}
	else
	{
		f = check();
		return f;
	}
}