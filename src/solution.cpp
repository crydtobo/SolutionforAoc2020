#include "../include/solution.h"

#define everyThridHash 3
#define everyHash 1

bool isProperlyPass(const int &count, const  int &n1, const int &n2){
    if (count >= n1 and count <= n2)
        return true;
    return false;
}

bool isCorrectPassword(const int i, const int n1, const std::string &pass, const char &letter){
    if ((i == ((size_t)n1 - 1)) && pass[i] == letter)
        return true;
    return false;
}


bool isprobablyCorrectPassword(const int i, const int n1){
    if (i == ((size_t)n1 - 1))
        return true;
    return false;
}

bool acceptedPassword(const int &flaga){
    if (flaga == 3 or flaga == 1)
        return true;
    return false;
}

int countCorrectletter(std::string pass, char letter){
	int count = 0;
	for (size_t i = 0; i < pass.size(); i++)
		{
			if (pass[i] == letter)
			{
				count++;
			}
		}
	return count;
}

bool everySecondLevel(const int &count){
    if (count > 0 && count % 2 == 0)
        return true;
    return false;
}

bool everyNumberHash(const std::string &line, const size_t &step, const int &n){
    if (line[n * step] == '#')
        return true;
    return false;
}

bool findHashFirst(const std::string &line, const size_t &step){
    if (line.size() - 1 >= 1 * step)
        return true;
    return false;
}

bool findHashSecond(const std::string &line, const size_t &step){
    if (line.size() < 1 * step + 1)
        return true;
    return false;
}

bool isEven(const int &count){
    if (count % 2 == 0)
        return true;
    return false;
}

std::tuple<int, int> solutionTask2(std::fstream &File2)
{
	int count = 0, n1 = 0, n2 = 0, line = 0, correct = 0, incorrect = 0;
	char letter, semicolon, dash;
	std::string pass;
	std::vector<std::string> passwords;

	while (File2 >> n1 >> dash >> n2 >> letter >> semicolon >> pass)
	{
		count = 0;
		line++;
		passwords.push_back(pass);
		count = countCorrectletter(pass, letter);
		if (isProperlyPass(count, n1, n2))
			correct++;
		else
			incorrect++;
	}
	std::tuple<int,int> res = {correct, incorrect};
	return res;
}

void firstPartTask2Prim(std::string &pass, char &letter, int &flaga, int &n1, int &n2)
{
    for (size_t i = 0; i < pass.size(); i++)
    {
        if (isCorrectPassword(i, n1, pass, letter))
        {
            flaga = 1;
        }
        else if (isprobablyCorrectPassword(i, n1))
        {
            flaga = 0;
        }
        else if (isCorrectPassword(i, n2, pass, letter))
        {
            flaga++;
        }
        else if (isprobablyCorrectPassword(i, n2))
        {
            flaga += 2;
        }
    }
}

std::tuple<int, int> solutionTask2Prim(std::fstream &File2)
{
    int n1 = 0, n2 = 0, line = 0, correct = 0, incorrect = 0, flaga = 0;
    char letter, semicolon, dash;
    std::string pass;

    while (File2 >> n1 >> dash >> n2 >> letter >> semicolon >> pass)
    {
        line++;
        firstPartTask2Prim(pass, letter, flaga, n1, n2);
        if (flaga == 2)
        {
            incorrect++;
        }
        else if (acceptedPassword(flaga)) 
        {
            correct++;
        }
        else
        {
            flaga = 0;
        }
    }
    std::tuple<int, int> res = {correct, incorrect};
    return res;
}

int incrementStep(const int &count, size_t &step){
    if (isEven(count))
        step++;
    return step;
}

void countCorrectTree(const std::string &line, int &tree, size_t &step)
{
    std::string l_line;
    while (findHashSecond(l_line, step))
    {
        l_line += line;
    }
    if (everyNumberHash(l_line, step, everyHash))
    {
        tree++;
    }
}

int countTree(const int &count, const std::string &line, int &tree, size_t &step)
{
    if (everySecondLevel(count))
    {
        if (findHashFirst(line, step) && everyNumberHash(line, step, everyThridHash))
        {
            tree++;
        }
        else
        {
            countCorrectTree(line, tree, step);
        }
    }
    return tree;
}

int soultionTask3(std::fstream &File)
{
    int count = 0, tree = 0;
    size_t step = 0;
    std::string line;
    while (File >> line)
    {
        countTree(count, line, tree, step);
        incrementStep(count, step);
        count++;
    }
    return tree;
}