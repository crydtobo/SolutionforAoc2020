#pragma once 

#include <string>
#include <memory>
#include <vector>

#include "taskFeatureFactory.h"
#include "../StrategyTaskSupport/strategy.h"

class Task
{
public:
    Task(std::shared_ptr<TaskFeatureFactory> featureFactory, const std::string &fileNamePara);

    std::string doTask();

private:
    std::shared_ptr<TaskFeatureFactory> featureFactory;
    std::vector<std::unique_ptr<Strategy>> features;

    void setTask();
    std::string fileName;
};