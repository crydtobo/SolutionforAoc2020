/*
 * task1.cpp
 *
 *  Created on: Dec 7, 2020
 *      Author: dawid
 */
#include <vector>
#include "../include/tasks1.h"

int multiply2D(const std::vector<int> &numbers){
	unsigned int i, j;
	int mul;
	for (i = 0; i < numbers.size(); i++)
	{
		for (j = 0; j < numbers.size(); j++)
		{
			if (numbers[i] + numbers[j] == 2020)
			{
				mul = numbers[i] * numbers[j];
			}
		}
	}
	return mul;
}

int multiply3D(const std::vector<int> &numbers){
	unsigned int i, j, k;
	int mul;
	for (i = 0; i < numbers.size(); i++)
	{
		for (j = 0; j < numbers.size(); j++)
		{
			for (k = 0; k < numbers.size(); k++)
			{
				if (numbers[i] + numbers[j] + numbers[k] == 2020)
				{
					mul = numbers[i] * numbers[j] * numbers[k];
				}
			}
		}
	}
	return mul;
}

int task1(std::fstream &File)
{
	int a = 0;
	std::vector<int> numbers;
	while (File >> a)
	{
		numbers.push_back(a);
	}
	return multiply2D(numbers);
}

int task1_prim(std::fstream &File1)
{
	int mul = 0;
	int a = 0;
	std::vector<int> numbers;
	while (File1 >> a)
	{
		numbers.push_back(a);
	} 
	return multiply3D(numbers);
}

void split_string(std::string &text)
{
	int i = 0;
	while (text[i] != '\0')
	{
		if (i % 2 == 0)
		{
			std::cout << "0x";
		}
		std::cout << text[i];
		++i;
		if (i % 2 == 0)
			std::cout << ", ";
		if (i % 40 == 0)
			std::cout << "\n";
	}
	std::cout << std::endl;
	std::cout << " Size: " << text.size() << std::endl;
}