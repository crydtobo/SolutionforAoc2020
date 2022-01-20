#pragma once

#include <memory>
#include <string>

#include "taskStrategyFactory.h"

class TaskFactory
{
public:
    explicit TaskFactory();
    std::unique_ptr<StrategyFactory> createTask(const std::string &input);

private:
    std::shared_ptr<StrategyFactory> concreteFactory;
};