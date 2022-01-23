#pragma once

#include <memory>
#include <string>

#include "task.h"

class TaskFactory
{
public:
    explicit TaskFactory();
    std::unique_ptr<Task> createTask(const std::string &fileName);

private:
    std::shared_ptr<TaskFeatureFactory> concreteFactory;
};