#include "../include/boarding_Pass.h"
#include <iostream>

std::vector<std::string> decode_input(std::fstream &file)
{
	std::string line;
	std::vector<std::string> pass_data;
	while (getline(file, line))
	{
		if (!line.empty())
		{
			pass_data.push_back(line);
		}
		else
		{
			break;
		}
	}
	return pass_data;
}
void Boarding_Pass ::row_reveal(std::string first)
{
	for (int i = 0; i < int(first.size()); i++)
	{
		if (first.at(i) == 'F')
		{
			upper = lower + (upper - 1 - lower) / 2;
		}
		else
		{
			lower = lower + (upper - 1 - lower) / 2 + 1;
		}
		if (lower == upper)
		{
			row = upper;
		}
	}
}

void Boarding_Pass ::column_reveal(std::string first)
{
	for (int i = 0; i < int(first.size()); i++)
	{
		if (first.at(i) == 'R')
		{
			l = l + (r + 1 - l) / 2;
		}
		else
		{
			r = l + (r - 1 - l) / 2;
		}
		if (l == r)
		{
			column = r;
		}
	}
}
int decode_seat(std::string i)
{
	std::string first;
	std::string second;
	Boarding_Pass object;
	int seat = 0;

	first = i.substr(0, i.size() - 3);
	second = i.substr(i.size() - 3, i.size());
	object.row_reveal(first);
	object.column_reveal(second);
	
	seat = 8 * object.row + object.column;
	return seat;
}