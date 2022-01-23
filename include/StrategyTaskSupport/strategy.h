/*
 * bags.h
 *
 *  Created on: Feb 25, 2021
 *      Author: dawid
 */
#ifndef INCLUDE_STRATEGY_H_
#define INCLUDE_STRATEGY_H_

#include <iostream>
#include <fstream>
#include <string>

class Strategy
{
public:
    virtual ~Strategy() = default;
    virtual std::string doThing(const std::string &file_name) const = 0;
};
#endif /* INCLUDE_STRATEGY_H_*/