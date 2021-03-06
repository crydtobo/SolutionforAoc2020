cmake_minimum_required(VERSION 3.16)
project(main VERSION 0.1.0 DESCRIPTION "Advent of Code 2020")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -g")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

SET(SRC 
        main.cpp 
        src/tasks.cpp
        src/boarding_Pass.cpp
        src/declaration.cpp 
        src/instructions.cpp 
        src/task1.cpp
        src/bags.cpp
        src/solution.cpp
        src/Passport/passportFactory.cpp
        src/Passport/passportFeatureFactory.cpp
        src/Passport/passportFeatureStrategy.cpp
        src/Passport/passportSupport.cpp
        src/StrategyTaskSupport/doExactStrategy.cpp
        src/TaskFactory/task.cpp
        src/TaskFactory/taskFactory.cpp
        src/TaskFactory/taskFeatureFactory.cpp
        tests/tests.cpp
    )

SET(GTEST_Files 
    gtest
    gtest_main
)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} ${TEST_LINK_LIBS} ${GTEST_Files} pthread )

#add_library(test_library STATIC test/test.cpp)
#include_directories(includes includes/calc)
 
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)
