#pragma once

#include "strategy.h"
#include "../tasks.h"

namespace
{
    const std::string INPUT1 = "input1.txt";
    const std::string INPUT2 = "input2.txt";
    const std::string INPUT3 = "input3.txt";
    const std::string INPUT4 = "input4.txt";
    const std::string INPUT5 = "input5.txt";
    const std::string INPUT6 = "input6.txt";
    const std::string INPUT7 = "input7.txt";
    const std::string INPUT8 = "input8.txt";
}

class Task1 : public Strategy
{
public:
    Task1(const std::string &fileName) : nameOfFile(fileName)
    {
    }
    
    std::string doThing(const std::string &fileName) const override
    {
        std::fstream file;
        openFile(file, nameOfFile);
        int res1 = task1(file);
        file.close();
        openFile(file, nameOfFile);
        int res2 = task1Prim(file);
        file.close();
        std::string result = logFromTask("Task1 - > Report Repair", res1, res2);
        return result;
    }

private:
    std::string nameOfFile;
};

class Task2 : public Strategy
{
public:
    Task2(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::fstream File2;
        openFile(File2, nameOfFile);
        int res1 = task2(File2);
        File2.close();
        openFile(File2, nameOfFile);
        int res2 = task2Prim(File2);
        File2.close();
        std::string result = logFromTask("Task2 - > Password Philosophy", res1, res2);
        return result;
    }

private:
    std::string nameOfFile;
};

class Task3 : public Strategy
{
public:
    Task3(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::fstream file;
        openFile(file, nameOfFile);
        int res1 = task3(file);
        file.close();
        openFile(file, nameOfFile);
        int res2 = task3Prim(file, res1);
        file.close();
        std::string result = logFromTask("Task3 - > Toboggan Trajectory", res1, res2);
        return result;
    }

private:
    std::string nameOfFile;
};

class Task4 : public Strategy
{
public:
    Task4(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::fstream file;
        openFile(file, nameOfFile);
        int res1 = task4(file);
        file.close();
        openFile(file, nameOfFile);
        int res2 = task4Prim(file);
        file.close();
        std::string result = logFromTask("Task4 -> Passport Processing", res1, res2);
        return result;
    }

private:
    std::string nameOfFile;
};

class Task5 : public Strategy
{
public:
    Task5(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::fstream file;
        openFile(file, nameOfFile);
        int res1 = task5(file);
        file.close();
        std::string result = logFromTask("Task5 -> Binary Boarding", res1);
        return result;
    }

private:
    std::string nameOfFile;
};

class Task6 : public Strategy
{
public:
    Task6(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::fstream file;
        openFile(file, nameOfFile);
        int res1 = task6(file);
        file.close();
        std::string result = logFromTask("Task6 -> Custom Customs", res1);
        return result;
    }

private:
    std::string nameOfFile;
};

class Task7 : public Strategy
{
public:
    Task7(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task7 -> Handy Haversacks" << std::endl;
        std::fstream file;
        openFile(file, nameOfFile);
        // int res1 = task7(file);
        std::string res = "It doesnt work now, I am planning do it in the near future ;)";
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Result: ") + std::string("\n") + std::string(res) + std::string("\n");
        return result;
    }

private:
    std::string nameOfFile;
};

class Task8 : public Strategy
{
public:
    Task8(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task8 -> Handheld Halting" << std::endl;
        std::fstream file;
        openFile(file, nameOfFile);
        // int res1 = task8(file);
        std::string res = "It doesnt work now, I am planning do it in the near future ;)";
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Result: ") + std::string("\n") + std::string(res) + std::string("\n");
        return result;
    }

private:
    std::string nameOfFile;
};

class Task9 : public Strategy
{
public:
    Task9(const std::string &fileName) : nameOfFile(fileName)
    {
    }

    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Podziel hex stringa na 2 bajtowe chunks " << std::endl;
        std::string text = "23D923C2FCCBF3D385BC067FD56C974218B83BD944575B80D700B9362FCD15EC3CD07B9664247DACE7479AD413DA4AF8B0038F093C39B20286821331D0D24B70E277C108AB4A7D667334C991839F6FA13F5F23F1D4A3A4C57D8387E138DE65895A74427CBB47004741EA80BDC103D5AE7083CDEFA9EF89EA8AE0A8236E8F676FCC23C8EAC0D74DEF4AE17AF7F8E7D5147B1F177290650C7F9CA9D01BFB6F2568740963479B9A3D5DC27EBB21B9C2F75CCD617DBF68F389619E6C210C0FD5DFACC08B9A1B57071FB75984B09BDDDE984A22F5E16A4AF031E4FB29A6DD1BF059A23619168988D6F94A95B2A746DC29818101D4664F5612B2689BB56CE1B664EE4C";
        std::cout << "przykladowy string: " << text << std::endl;
        splitString(text);
        std::string result = std::string("For string: ") + std::string("\n") + std::string(text) + std::string("\n") + std::string("Answer: above\n");
        return result;
    }

private:
    std::string nameOfFile;
};