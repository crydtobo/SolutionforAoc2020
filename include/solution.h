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

//boolean funcions
bool isProperlyPass(const int &count, const  int &n1, const int &n2);
bool isprobablyCorrectPassword(const int i, const int n1);
bool isCorrectPassword(const int i, const int n1, const std::string &pass, const char &letter);
bool acceptedPassword(const int &flaga);
bool everySecondLevel(const int &count);
bool everyNumberHash(const std::string &line, const size_t &step, const int &n);
bool findHashFirst(const std::string &line, const size_t &step);
bool findHashSecond(const std::string &line, const size_t &step);
bool isEven(const int &count);
bool isCorrectPassportForHeaders(const std::size_t &found, const std::string &pass);
bool isCorrectBasicPassport(const std::string &passport);

int countPassletter(std::string pass, char letter);
void firstPartTask2Prim(std::string &pass, char &letter, int &flaga, int &n1, int &n2);

std::tuple<int, int> solutionTask2(std::fstream &File2);
std::tuple<int, int> solutionTask2Prim(std::fstream &File2);

int soultionTask3(std::fstream &File);
int soultionTask3prim(std::fstream &File, const int &option);
int solutionTask4(std::fstream &File);
int checkSolutionTask5(const std::vector<int> &maxi);

#endif //INCLUDE_SOLUTION_H_