/*
 * task2.cpp
 *
 *  Created on: Dec 8, 2020
 *      Author: dawid
 */
#include "../include/tasks.h"
#include "../include/boarding_Pass.h"
#include "../include/declaration.h"
#include "../include/bags.h"
#include "../include/instruction.h"
#include "../include/asn1.h"
#include "../include/solution.h"
#include "../include/Passport/passportFactory.h"
#include "../include/StrategyTaskSupport/concretStrategy.h"

std::string logFromTask(const std::string &message, const int &result1, const int result2)
{
    std::cout << message << std::endl;
    std::string result = std::string("Part1: ") + std::to_string(result1) + std::string("\n") +
                         std::string("Part2: ") + std::to_string(result2);
    return result;
}

void openFile(std::fstream &file, const std::string &fileName)
{
	file.open(std::string(config) + std::string(fileName), std::ios::in);
	if (!file)
	{
		std::cout << "Error, incorrect opening file!" << std::endl;
	}
}

unsigned int task3Prim(std::fstream &file, const int &first_mul)
{
	unsigned int resulter = 0;
	int option = 1;
	int result = 0, mul = 1;
	while (option < 8)
	{
		file.close();
		openFile(file, INPUT3);
		result = task3PrimResult(file, option);
		mul *= result;
		option += 2;
	}
	return first_mul * mul;
}

int task2(std::fstream &File2)
{
	std::tuple<int, int> res = solutionTask2(File2);
	return std::get<0>(res);
}

int task2Prim(std::fstream &File2)
{
	std::tuple<int, int> res = solutionTask2Prim(File2);
	return std::get<0>(res);
}

int task3(std::fstream &File)
{
	int tree = 0;
	tree = soultionTask3(File);
	return tree;
}

int task3PrimResult(std::fstream &File3, const int &option)
{
	int tree = soultionTask3Prim(File3, option);
	return tree;
}

int task4(std::fstream &file)
{
	return solutionTask4(file);
}

int task4Prim(std::fstream &file)
{
	int count_correct = 0;
	std::vector<std::string> p = parseForNewPassport(file);
	PassportFactory factoryPassport {};

	for (auto i : p)
	{
		auto passport = factoryPassport.createPassport(i);
		if (passport->isValid())
		{
			count_correct++;
		}
	}
	return count_correct;
}

int task5(std::fstream &file)
{
	int max = 0;
	std::vector<std::string> t = decodeInput(file);
	std::vector<int> maxi;
	for (auto i : t)
	{
		max = decodeSeat(i);
		maxi.push_back(max);
	}
	std::sort(maxi.begin(), maxi.end());
	return checkSolutionTask5(maxi);
}

int task6(std::fstream &file)
{
	int solution = 0;
	Declaration object;
	std::vector<std::vector<std::string>> t2 = parseFile2(file);
	object.checkSecond(t2);
	solution = object.sum;
	return solution;
}

/*
int task7(std::fstream &file)
{
	Bags object;
	Bags::contained_t contained;
	Bags::contains_t contains;

	std::vector<std::string> b = decodeInput(file);
	object.parse_input(b, contained, contains);

	auto bags = contains["shiny gold"];
	std::deque<std::string> q({"shiny gold"});
	std::unordered_set<std::string> seen({"shiny gold"});
	while (!q.empty())
	{
		std::string bagName = q.front();
		for (auto &bag : contained[bag_name])
		{
			if (seen.insert(bag).second)
			{
				q.push_back(bag);
			}
		}
		q.pop_front();
	}
	
	uint32_t numbers = object.countBags(contains, "shiny gold");
	std::cout << "Solution 2: " << numbers << std::endl;
	std::cout << "Solution 1: ";
	return seen.size();
}
*/

int projectEuler()
{
	int result{0};
	result = one();
	result = fibonnaci();
	return result;
}

int one()
{
	int game{0};
	for (int i = 1; i < 1000; i++)
	{
		if ((i % 3 == 0) or (i % 5 == 0))
		{
			game += i;
		}
	}
	return game;
}

int fibonnaci()
{
	int y = 0, x = 1, next = 0, sum = 0;
	int theEnd = (4 * (pow(10, 6)));
	while (next < theEnd)
	{
		next = y + x;
		y = x;
		x = next;
		if (next % 2 == 0)
		{
			sum += next;
		}
	}

	return sum;
}

int task8(std::fstream &file)
{
	int solution{0};
	std::vector<std::string> result;
	//result = decode_input(file);
	//Instruction obj;
	//obj.reading_instructions(result);
	return solution;
}

//ASN1 decoding BER
void encodeTag(std::vector<uint8_t> &encodedTag, ASN1_Tag classTagA, ASN1_Tag typeTagA)
{
	const uint32_t classTag = static_cast<uint32_t>(classTagA);
	const uint32_t typeTag = static_cast<uint32_t>(typeTagA);

	if (classTag != 0x00)
	{
		std::cout << "DER encoding error, should be 0x00 (tag:universal) but is" + std::to_string(classTag) << std::endl;
	}
	
	if (typeTag <= 30)
	{
		encodedTag.push_back(static_cast<uint8_t>(typeTag | classTag));
	}
	else
	{
		size_t blocks = high_bit(static_cast<uint32_t>(typeTag)) + 6;
		blocks = (blocks - (blocks % 7)) / 7;
		assert(blocks > 0);

		encodedTag.push_back(static_cast<uint8_t>(classTag | 0x1F));
		for (size_t i = 0; i != blocks - 1; ++i)
			encodedTag.push_back(0x80 | ((typeTag >> 7 * (blocks - i - 1)) & 0x7F));
		encodedTag.push_back(typeTag & 0x7F);
	}
}

void taskCert(std::fstream &file)
{
	int solution;

	std::vector<std::string> result;
	std::vector<uint8_t> m;
	std::vector<std::vector<uint8_t>> m_set_contents;

	std::vector<uint8_t> encoded;
	encodeTag(encoded, ASN1_Tag::UNIVERSAL, ASN1_Tag::OCTET_STRING);

	uint32_t test = 0x023000000;
	auto test_result = significant_bytes(test);
	std::cout << "Result significant : " << test_result << std::endl;

	size_t blocks = high_bit(static_cast<uint32_t>(ASN1_Tag::APPLICATION));
	std::cout << "Blocks: : " << blocks << std::endl;
	std::cout << "Make Pair::" << std::endl;

	size_t len = 10;
	const uint8_t add[] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A};
	m.reserve(len);
	for (int i = 0; i < 10; i++)
	{
		m += std::make_pair(add, len);
		m_set_contents.push_back(std::move(m));
	}
}
