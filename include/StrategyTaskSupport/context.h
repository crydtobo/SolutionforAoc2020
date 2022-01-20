#pragma once
#include "strategy.h"
#include <memory>

class Context
{
private:
    std::unique_ptr<Strategy> strategy;

public:
    Context(std::unique_ptr<Strategy> exact_strategy)
    {
        strategy = std::move(exact_strategy);
    }

    ~Context() {}

    void setStrategy(std::unique_ptr<Strategy> exact_strategy)
    {
        strategy = std::move(exact_strategy);
    }

    void doMainTask(const std::string &inputFile) const
    {
        std::cout << "Task for " << inputFile << std::endl;
        std::string result = strategy->doThing(inputFile);
        std::cout << result << std::endl;
    }
};