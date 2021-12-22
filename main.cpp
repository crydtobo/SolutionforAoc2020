#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

#include "include/tasks.h"
#include "include/StrategyPattern/doExactStrategy.h"

int main(int argc, char **argv)
{
    //Google Testy
    std::cout << "Google Testy" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    auto ret = RUN_ALL_TESTS();

    //main dla zadan
    doTask();
    
    return ret;
}