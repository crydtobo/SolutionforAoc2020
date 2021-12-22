#include "../include/solution.h"

#define EVERY_THIRD_HASH 3
#define EVERY_HASH 1

bool isProperlyPass(const int &count, const  int &n1, const int &n2){
    return (count >= n1 and count <= n2);
}

bool isprobablyCorrectPassword(const int i, const int n1){
    return (i == ((size_t)n1 - 1));
}

bool isCorrectPassword(const int i, const int n1, const std::string &pass, const char &letter){
    return ((isprobablyCorrectPassword(i,n1)) && pass[i] == letter);
}

bool acceptedPassword(const int &flaga){
    return (flaga == 3 or flaga == 1);
}

bool everySecondLevel(const int &count){
    return (count > 0 && count % 2 == 0);
}

bool everyNumberHash(const std::string &line, const size_t &step, const int &n){
    return (line[n* step] == '#');
}

bool findHashFirst(const std::string &line, const size_t &step){
    return (line.size() - 1 >= step);
}

bool findHashSecond(const std::string &line, const size_t &step){
    return (line.size() < step + 1);
}

bool isEven(const int &count){
    return (count % 2 == 0);
}

bool isCorrectPassportForHeaders(const std::size_t &found, const std::string &pass){
	return (std::count(pass.begin(), pass.end(), ':') == 7
	 && (found == std::string::npos));
}

bool isCorrectBasicPassport(const std::string &passport){
	return (std::count(passport.begin(), passport.end(), ':') == 8);
}

int countCorrectLetter(std::string pass, char letter){
    return std::count(pass.begin(), pass.end(), letter);
}

int countCorrectPassword(const int &count, const int &n1, const int &n2)
{
    return (isProperlyPass(count, n1, n2)) ?  1 : 0;
}

std::tuple<int, int> solutionTask2(std::fstream &File2)
{
	int count = 0, n1 = 0, n2 = 0, line = 0, correct = 0, incorrect = 0;
	char letter, semicolon, dash;
	std::string pass;
	std::vector<std::string> passwords;
    std::tuple<int,int> res;

	while (File2 >> n1 >> dash >> n2 >> letter >> semicolon >> pass)
	{
		count = 0;
		line++;
		passwords.push_back(pass);
		count = countCorrectLetter(pass, letter);
		correct += countCorrectPassword(count, n1, n2);
	}
    incorrect = count - correct;
	res = {correct, incorrect};

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

int countCorrectBags(int &flaga)
{
    if (acceptedPassword(flaga))
    {
        return 1;
    }
    else if (flaga == 2)
    {
        return 0;
    }
    else
    {
        flaga = 0;
        return 0;
    }
    return 0;
}

std::tuple<int, int> solutionTask2Prim(std::fstream &File2)
{
    int n1 = 0, n2 = 0, correct = 0, incorrect = 0, flaga = 0, all;
    char letter, semicolon, dash;
    std::string pass;

    while (File2 >> n1 >> dash >> n2 >> letter >> semicolon >> pass)
    {
        all++;
        firstPartTask2Prim(pass, letter, flaga, n1, n2);
        correct += countCorrectBags(flaga);
    }

    std::tuple<int, int> res = {correct, all - correct};
    return res;
}

int incrementStep(const int &count, size_t &step){
    return (isEven(count)) ? step++ : step; 
}

std::string copyLineIfHash(const std::string &line, size_t &step){
    std::string new_line;

    while (findHashSecond(new_line, step))
    {
        new_line += line;
    }

    return new_line;
}

int incrementTreeIfHash(const std::string &new_line, size_t &step)
{
    return (everyNumberHash(new_line, step, EVERY_HASH)) ? 1 : 0;
}

void countCorrectTree(const std::string &line, int &tree, size_t &step)
{
    //increment tree
    std::string new_line = copyLineIfHash(line, step);
    tree += incrementTreeIfHash(new_line,step);
}


void countFoundHash(const std::string &line, int &tree, size_t &step)
{
    if (findHashFirst(line, step) && everyNumberHash(line, step, EVERY_THIRD_HASH))
    {
        tree++;
    }
    else
    {
        countCorrectTree(line, tree, step);
    }
}

int countTree(const int &count, const std::string &line, int &tree, size_t &step)
{
    if (everySecondLevel(count))
        countFoundHash(line, tree, step);
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

int soultionTask3Prim(std::fstream &File, const int &option){
    int count = 0, tree = 0;
	size_t step = 0;
	size_t traverse = 0;
	std::string line;
	while (File >> line)
	{
		//zmiana opcji przechodzenia
		traverse = option * step;
		if (count > 0)
		{
			if (findHashFirst(line, traverse) && line[traverse] == '#')
			{
				tree++;
			}
			else
			{
				countCorrectTree(line, tree, traverse);
			}
		}
		step++;
		count++;
	}
    return tree;
}

int countCorrectPassport(const std::string &passport)
{
    std::size_t found = passport.find("cid");
    return (isCorrectBasicPassport(passport) || isCorrectPassportForHeaders(found, passport)) ? 1 : 0;
}

int solutionTask4(std::fstream &File)
{
    int countCorrect = 0;
    std::string line;
    std::string passport = "";

    while (getline(File, line))
    {
        if (!line.empty())
        {
            passport = passport + " " + line;
        }
        else
        {
            countCorrect += countCorrectPassport(passport);
            passport = "";
        }
    }

    return countCorrect + 1;
}

bool biggerOne(const int &first, const int &second){
    return (first != second) ? 1 : 0;
}

int checkSolutionTask5(const std::vector<int> &maxi)
{
	int solution = *max_element(maxi.begin(), maxi.end());
	for (int k = 0; k < maxi.size(); k++)
	{
		if (biggerOne(maxi[k] + 1, maxi[k + 1]))
		{
			return maxi[k] + 1;
		}
	}

	return solution;
}