#include "../../include/StrategyTaskSupport/taskStrategyFactory.h"

StrategyFactory::StrategyFactory(){
    initializeConcretTask();
}

std::unique_ptr<Strategy> StrategyFactory::getTask(const std::string &key, const std::string &argForFunction){
    auto it = casesOfTask.find(key);
    handleNonExistTask(it);
    return it->second(argForFunction);
}

void StrategyFactory::initializeConcretTask(){
     concreteTask task1 = std::bind(&StrategyFactory::getTask1, this, std::placeholders::_1);
     casesOfTask.emplace("1", task1);

     concreteTask task2 = std::bind(&StrategyFactory::getTask2, this, std::placeholders::_1);
     casesOfTask.emplace("2", task2);

     concreteTask task3 = std::bind(&StrategyFactory::getTask3, this, std::placeholders::_1);
     casesOfTask.emplace("3", task3);

     concreteTask task4 = std::bind(&StrategyFactory::getTask4, this, std::placeholders::_1);
     casesOfTask.emplace("4", task4);

     concreteTask task5 = std::bind(&StrategyFactory::getTask5, this, std::placeholders::_1);
     casesOfTask.emplace("5", task5);

     concreteTask task6 = std::bind(&StrategyFactory::getTask6, this, std::placeholders::_1);
     casesOfTask.emplace("6", task6);

     concreteTask task7 = std::bind(&StrategyFactory::getTask7, this, std::placeholders::_1);
     casesOfTask.emplace("7", task7);

     concreteTask task8 = std::bind(&StrategyFactory::getTask8, this, std::placeholders::_1);
     casesOfTask.emplace("8", task8);
}

void StrategyFactory::handleNonExistTask(const std::unordered_map<std::string, concreteTask>::iterator &it){
    if(it != casesOfTask.end()){
        throw std::runtime_error("Wrong TASK! CasesOfTask dont include task!");
    }
}

std::unique_ptr<Strategy> StrategyFactory::getTask1(const std::string &input){
    return std::make_unique<Task1>(input);
}

std::unique_ptr<Strategy> StrategyFactory::getTask2(const std::string &input){
    return std::make_unique<Task2>(input);
}

std::unique_ptr<Strategy> StrategyFactory::getTask3(const std::string &input){
    return std::make_unique<Task3>(input);
}

std::unique_ptr<Strategy> StrategyFactory::getTask4(const std::string &input){
    return std::make_unique<Task4>(input);
}

std::unique_ptr<Strategy> StrategyFactory::getTask5(const std::string &input){
    return std::make_unique<Task5>(input);
}

std::unique_ptr<Strategy> StrategyFactory::getTask6(const std::string &input){
    return std::make_unique<Task6>(input);
}

std::unique_ptr<Strategy> StrategyFactory::getTask7(const std::string &input){
    return std::make_unique<Task7>(input);
}

std::unique_ptr<Strategy> StrategyFactory::getTask8(const std::string &input){
    return std::make_unique<Task8>(input);
}

