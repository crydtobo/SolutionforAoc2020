/*
 * task.h
 *
 *  Created on: Dec 8, 2020
 *      Author: dawid
 */
#ifndef INCLUDE_TASKS_H_
#define INCLUDE_TASKS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "bags.h"
#include "tasks1.h"
#include "asn1.h"

//sciezka do plikow testowych na Twoim komputerze/
//pliki znjaduja sie w folderze projektowym /src/inputs
#define config "/home/dawid/Projects/C_C++/Aoc_2020/src/inputs/"

//sciezka do plikow testowych w folderze /input w /src
//#define config "../src/inputs/"

#define DEFAULT_OPTION 1

void openFile(std::fstream &file, const std::string &fileName);
std::string logFromTask(const std::string &message, const int &result1, const int result2 = 0);

unsigned int task3Prim(std::fstream &file, const int &first_mul);

int task2(std::fstream &file);
int task2Prim(std::fstream &file);
int task3(std::fstream &file);
int task3PrimResult(std::fstream &file, const int &option = DEFAULT_OPTION);
int task4(std::fstream &file);
int task4Prim(std::fstream &file);
int task5(std::fstream &file);
int task6(std::fstream &file);
//int task7(std::fstream &file);
int task8(std::fstream &file);

//tasks with ASN1 and math problems
void taskCert(std::fstream &file);
void encodeTag(std::vector<uint8_t> &encoded_tag, ASN1_Tag class_tag, ASN1_Tag tag_a);

int projectEuler();
int one();
int fibonnaci();
int three();


#endif /* INCLUDE_TASKS_H_ */