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

//sciezka do plikow testowych w folderze /input w /src
#define config "../src/inputs/"


//zdefiniuj sciezke do folderu z plikami wejsciowymi na twoim komputerze
//#define config "/home/dawid/Projects/C_C++/Aoc_2020/src/inputs/"

void openFile(std::fstream &file, const std::string &fileName);

int task2(std::fstream &file);
int task2_prim(std::fstream &file);
int task3(std::fstream &file);
unsigned int task3Prim(std::fstream &file, const int &first_mul);
int task3_prim(std::fstream &file, const int &option = 1);
int task4(std::fstream &file);
int task4_prim(std::fstream &file);
int task5(std::fstream &file);
int task6(std::fstream &file);
//int task7(std::fstream &file);
int task8(std::fstream &file);

//tasks with ASN1 and math problems
void task_cert(std::fstream &file);
void encode_tag(std::vector<uint8_t> &encoded_tag, ASN1_Tag class_tag, ASN1_Tag tag_a);
int project_euler();
int one();
int fibonnaci();
int three();


#endif /* INCLUDE_TASKS_H_ */