#include "../../include/TaskFactory/taskFeatureFactory.h"

TaskFeatureFactory::TaskFeatureFactory(){
    initializeConcretTask();
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask(const std::string &nameOfFile){
    auto it = casesOfTask.find(nameOfFile);
    handleNonExistTask(it);
    return it->second(nameOfFile);
}

void TaskFeatureFactory::initializeConcretTask(){
     concreteTask task1 = std::bind(&TaskFeatureFactory::getTask1, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT1, task1);

     concreteTask task2 = std::bind(&TaskFeatureFactory::getTask2, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT2, task2);

     concreteTask task3 = std::bind(&TaskFeatureFactory::getTask3, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT3, task3);

     concreteTask task4 = std::bind(&TaskFeatureFactory::getTask4, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT4, task4);

     concreteTask task5 = std::bind(&TaskFeatureFactory::getTask5, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT5, task5);

     concreteTask task6 = std::bind(&TaskFeatureFactory::getTask6, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT6, task6);

     concreteTask task7 = std::bind(&TaskFeatureFactory::getTask7, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT7, task7);

     concreteTask task8 = std::bind(&TaskFeatureFactory::getTask8, this, std::placeholders::_1);
     casesOfTask.emplace(INPUT8, task8);
}

void TaskFeatureFactory::handleNonExistTask(const std::unordered_map<std::string, concreteTask>::iterator &it){
    if(it == casesOfTask.end()){
        throw std::runtime_error("Wrong TASK! CasesOfTask dont include task!");
    }
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask1(const std::string &input){
    return std::make_unique<Task1>(input);
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask2(const std::string &input){
    return std::make_unique<Task2>(input);
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask3(const std::string &input){
    return std::make_unique<Task3>(input);
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask4(const std::string &input){
    return std::make_unique<Task4>(input);
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask5(const std::string &input){
    return std::make_unique<Task5>(input);
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask6(const std::string &input){
    return std::make_unique<Task6>(input);
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask7(const std::string &input){
    return std::make_unique<Task7>(input);
}

std::unique_ptr<Strategy> TaskFeatureFactory::getTask8(const std::string &input){
    return std::make_unique<Task8>(input);
}

