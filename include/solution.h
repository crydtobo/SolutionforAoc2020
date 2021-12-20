#ifndef INCLUDE_SOLUTION_H_
#define INCLUDE_SOLUTION_H_

#include <tuple>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <array>
#include <iterator>
#include <cmath>


int countPassletter(std::string pass, char letter);
void firstPartTask2Prim(std::string &pass, char &letter, int &flaga, int &n1, int &n2);

std::tuple<int, int> solutionTask2(std::fstream &File2);
std::tuple<int, int> solutionTask2Prim(std::fstream &File2);

int soultionTask3(std::fstream &File);

#endif //INCLUDE_SOLUTION_H_