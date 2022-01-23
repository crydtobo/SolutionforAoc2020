#include "../../include/TaskFactory/taskFactory.h"

TaskFactory::TaskFactory() : concreteFactory(std::make_shared<TaskFeatureFactory>()) {}

std::unique_ptr<Task> TaskFactory::createTask(const std::string &fileName)
{
    return std::make_unique<Task>(concreteFactory,fileName);
}