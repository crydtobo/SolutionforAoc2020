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

int task2(std::fstream &file);
int task2_prim(std::fstream &file);
int task3(std::fstream &file);
int task3_prim(std::fstream &file, const int &option = 1);
int task4(std::fstream &file);
int task4_prim(std::fstream &file);
int task5(std::fstream &file);
int task6(std::fstream &file);
//int task7(std::fstream &file);
int task8(std::fstream &file);
int task_cert(std::fstream &file);
int project_euler();
int one();
int fibonnaci();
int theLargestPrimeFactor();
int three();

#endif /* INCLUDE_TASKS_H_ */