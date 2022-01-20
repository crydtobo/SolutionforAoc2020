#pragma once

#include "concretStrategy.h"
#include <iterator>

class StrategyFactory
{
public:
    StrategyFactory();
    ~StrategyFactory() = default;
    std::unique_ptr<Strategy> getTask(const std::string &key, const std::string &argForFunction);

private:
    typedef std::function<std::unique_ptr<Strategy>(const std::string &input)> concreteTask;
    std::unordered_map<std::string, concreteTask> casesOfTask;

    void initializeConcretTask();
    void handleNonExistTask(const std::unordered_map<std::string, concreteTask>::iterator &it);

    std::unique_ptr<Strategy> getTask1(const std::string &input);
    std::unique_ptr<Strategy> getTask2(const std::string &input);
    std::unique_ptr<Strategy> getTask3(const std::string &input);
    std::unique_ptr<Strategy> getTask4(const std::string &input);
    std::unique_ptr<Strategy> getTask5(const std::string &input);
    std::unique_ptr<Strategy> getTask6(const std::string &input);
    std::unique_ptr<Strategy> getTask7(const std::string &input);
    std::unique_ptr<Strategy> getTask8(const std::string &input);
};