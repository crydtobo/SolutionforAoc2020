#include "../../include/StrategyTaskSupport/taskFactory.h"

TaskFactory::TaskFactory() : concreteFactory(std::make_shared<StrategyFactory>()) {}

std::unique_ptr<StrategyFactory> TaskFactory::createTask(const std::string &input)
{
    return std::make_unique<StrategyFactory>(concreteFactory, input);
}