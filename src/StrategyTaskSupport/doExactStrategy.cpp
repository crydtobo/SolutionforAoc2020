
#include "../../include/StrategyTaskSupport/doExactStrategy.h"
#include "../../include/StrategyTaskSupport/context.h"
#include "../../include/StrategyTaskSupport/taskFactory.h"

std::string chosenFileasInput(int chosen){
    
}

int getUserInput()
{
    int cases = 0;
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++ Aoc2020 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Podaj numer zadania od 1 do 9 \n";
    std::cin >>cases;
    return cases;
}

void doTask()
{
    
    std::string inputFileName;
    int cases = getUserInput();
    //TaskFactory factory {};
    //factory.createTask(INPUT1);

    // //stworzenie Instacji Content(Interfejs dla wzora Startegia)
    // Context context(std::make_unique<Task1>());

    // switch (cases)
    // {
    // case 1:
    // {
    //     context.setStrategy(std::make_unique<Task1>());
    //     inputFileName = INPUT1;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // case 2:
    // {
    //     context.setStrategy(std::make_unique<Task2>());
    //     inputFileName = INPUT2;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // case 3:
    // {
    //     context.setStrategy(std::make_unique<Task3>());
    //     inputFileName = INPUT3;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // case 4:
    // {
    //     context.setStrategy(std::make_unique<Task4>());
    //     inputFileName = INPUT4;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // case 5:
    // {
    //     context.setStrategy(std::make_unique<Task5>());
    //     inputFileName = INPUT5;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // case 6:
    // {
    //     context.setStrategy(std::make_unique<Task6>());
    //     inputFileName = INPUT6;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // case 7:
    // {
    //     context.setStrategy(std::make_unique<Task7>());
    //     inputFileName = INPUT7;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // case 8:
    // {
    //     context.setStrategy(std::make_unique<Task8>());
    //     inputFileName = INPUT8;
    //     context.doMainTask(inputFileName);

    // }
    // break;
    // case 9:
    // {
    //     context.setStrategy(std::make_unique<Task9>());
    //     inputFileName = INPUT8;
    //     context.doMainTask(inputFileName);
    // }
    // break;
    // default:
    // {
    //     std::cout << "Default" << std::endl;
    // }
    // }
}
