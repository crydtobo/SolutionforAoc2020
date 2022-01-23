
#include "../../include/StrategyTaskSupport/doExactStrategy.h"
#include "../../include/StrategyTaskSupport/context.h"
#include "../../include/TaskFactory/taskFactory.h"

std::string getUserInput()
{
    std::string cases;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++ Aoc2020 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Podaj numer zadania od 1 do 9 \n";
    std::cin >> cases;
    return cases;
}

std::string chosenFileasInput()
{
    std::string inputFileName;
    std::string cases = getUserInput();
    std::string nameOfInputFile = std::string("input") + cases + std::string(".txt");
    return nameOfInputFile;
}

void doTask()
{
    auto input = chosenFileasInput();
    TaskFactory factory;
    auto task = factory.createTask(input);
    std::cout << "Result factory: " << task->doTask() << std::endl;
}
