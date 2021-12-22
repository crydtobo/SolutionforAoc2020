#include "strategy.h"
#include "../tasks.h"

#define INPUT1 "input1.txt"
#define INPUT2 "input2.txt"
#define INPUT3 "input3.txt"
#define INPUT4 "input4.txt"
#define INPUT5 "input5.txt"
#define INPUT6 "input6.txt"
#define INPUT7 "input7.txt"
#define INPUT8 "input8.txt"

class Task1 : public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task1 - > Report Repair" << std::endl;
        std::fstream file;
        openFile(file, INPUT1);
        int res1 = task1(file);
        file.close();
        openFile(file, INPUT1);
        int res2 = task1Prim(file);
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Part1: ") + std::to_string(res1) + std::string("\n") +
                             std::string("Part2: ") + std::to_string(res2);
        return result;
    }
};

class Task2 : public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task2 - > Password Philosophy" << std::endl;
        std::fstream File2;
        openFile(File2, INPUT2);
        int res1 = task2(File2);
        File2.close();
        openFile(File2, INPUT2);
        int res2 = task2Prim(File2);
        File2.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Part1: ") + std::to_string(res1) + std::string("\n") +
                             std::string("Part2: ") + std::to_string(res2);
        return result;
    }
};

class Task3 : public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task3 - > Toboggan Trajectory" << std::endl;
        std::fstream file;
        openFile(file, INPUT3);
        int res1 = task3(file);
        file.close();
        openFile(file, INPUT3);
        int res2 = task3Prim(file, res1);
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Part1: ") + std::to_string(res1) + std::string("\n") +
                             std::string("Part2: ") + std::to_string(res2);
        return result;
    }
};

class Task4 : public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task4 -> Passport Processing" << std::endl;
        std::fstream file;
        openFile(file, INPUT4);
        int res1 = task4(file);
        file.close();
        openFile(file, INPUT4);
        int res2 = task4Prim(file);
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Part1: Number of valid passport: ") + std::to_string(res1) + std::string("\n") +
                             std::string("Part2: Number of valid passport: ") + std::to_string(res2);
        return result;
    }
};

class Task5 : public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task5 -> Binary Boarding" << std::endl;
        std::fstream file;
        openFile(file, INPUT5);
        int res1 = task5(file);
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Max seat ID: ") + std::to_string(res1) + std::string("\n");
        return result;
    }
};

class Task6 : public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task6 -> Custom Customs" << std::endl;
        std::fstream file;
        openFile(file, INPUT6);
        int res1 = task6(file);
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Result: ") + std::to_string(res1) + std::string("\n");
        return result;
    }
};

class Task7 : public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task7 -> Handy Haversacks" << std::endl;
        std::fstream file;
        openFile(file, INPUT7);
        //int res1 = task7(file);
        std::string res = "It doesnt work now, I am planning do it in the near future ;)";
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Result: ") + std::string("\n") + std::string(res) + std::string("\n");
        return result;
    }
};

class Task8: public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Task8 -> Handheld Halting" << std::endl;
        std::fstream file;
        openFile(file, INPUT7);
        //int res1 = task8(file);
        std::string res = "It doesnt work now, I am planning do it in the near future ;)";
        file.close();
        std::cout << "File is closed correctly " << std::endl;
        std::string result = std::string("Result: ") + std::string("\n") + std::string(res) + std::string("\n");
        return result;
    }
};

class Task9: public Strategy
{
public:
    std::string doThing(const std::string &file_name) const override
    {
        std::cout << "Podziel hex stringa na 2 bajtowe chunks " << std::endl;
        std::string text = "23D923C2FCCBF3D385BC067FD56C974218B83BD944575B80D700B9362FCD15EC3CD07B9664247DACE7479AD413DA4AF8B0038F093C39B20286821331D0D24B70E277C108AB4A7D667334C991839F6FA13F5F23F1D4A3A4C57D8387E138DE65895A74427CBB47004741EA80BDC103D5AE7083CDEFA9EF89EA8AE0A8236E8F676FCC23C8EAC0D74DEF4AE17AF7F8E7D5147B1F177290650C7F9CA9D01BFB6F2568740963479B9A3D5DC27EBB21B9C2F75CCD617DBF68F389619E6C210C0FD5DFACC08B9A1B57071FB75984B09BDDDE984A22F5E16A4AF031E4FB29A6DD1BF059A23619168988D6F94A95B2A746DC29818101D4664F5612B2689BB56CE1B664EE4C";
        std::cout << "przykladowy string: " << text << std::endl;
        splitString(text);
        std::string result = std::string("For string: ") + std::string("\n") + std::string(text) + std::string("\n") + std::string("Answer: above\n");
        return result;
    }
};