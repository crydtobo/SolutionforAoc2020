#include "../../include/TaskFactory/task.h"

Task::Task(std::shared_ptr<TaskFeatureFactory> featureFactoryPara, const std::string &fileNamePara)
            : featureFactory(featureFactoryPara), fileName(fileNamePara){
                setTask();
            }

void Task::setTask(){
    auto strategy = featureFactory->getTask(fileName);
    features.push_back(std::move(strategy));
}

std::string Task::doTask(){
    std::string result;
    for (auto &feature : features)
     {
        result = feature->doThing(fileName);
     }
    return result;
}