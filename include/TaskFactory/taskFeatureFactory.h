#pragma once

#include "../StrategyTaskSupport/concretStrategy.h"
#include <iterator>

class TaskFeatureFactory
{
public:
    TaskFeatureFactory();
    std::unique_ptr<Strategy> getTask(const  std::string &nameOfFile);

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