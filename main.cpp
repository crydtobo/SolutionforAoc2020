#include <iostream>
#include <fstream>
#include <gtest/gtest.h>

#include "include/tasks.h"

int main(int argc, char **argv)
{
    //Google Testy
    std::cout << "Google Testy" << std::endl;
    testing::InitGoogleTest(&argc, argv);
    auto ret = RUN_ALL_TESTS();

    //return ret;

    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++ Aoc2020 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Jezeli jeszcze tego nie zrobiles to zdefiniuj sciezke do plikow wejsciowych!. \n Docelowo znajduja sie w folderze projektu w /src/inputs. W pliku main.cpp w 6 lini zdefiniowany config do podania sciezki\n #define config <sciezka> \n";
    std::cout << "+++++++++++++++++++++++++++++++++++++++++++++++ Aoc2020 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    std::cout << "Podaj numer zadania od 1 do 9 \n";
    int cases = 0;
    std::cin >> cases;
    switch (cases)
    {
    case 1:
    {
        std::cout << "Task1 - > Report Repair" << std::endl;
        std::fstream File1;
        File1.open(std::string(config) + std::string("input1.txt"), std::ios::in);
        if (!File1)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Result Part1: " << task1(File1) << std::endl;
            File1.close();
            File1.open(std::string(config) + std::string("input1.txt"), std::ios::in);
            std::cout << "Result Part2: " << task1_prim(File1) << std::endl;
        }
        File1.close();
        std::cout << "File is closed correctly " << std::endl;
    }
    break;
    case 2:
    {
        std::cout << "Task2 - > Password Philosophy" << std::endl;
        std::fstream File2;
        File2.open(std::string(config) + std::string("input2.txt"), std::ios::in);
        if (!File2)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Result Part1:" << std::endl;
            task2(File2);
            File2.close();
            File2.open(std::string(config) + std::string("input2.txt"), std::ios::in);
            std::cout << "Result Part2:" << std::endl;
            task2_prim(File2);
        }
        File2.close();
        std::cout << "File is closed correctly " << std::endl;
    }
    break;
    case 3:
    {
        std::fstream File3;
        std::cout << "Task3 - > Toboggan Trajectory" << std::endl;

        File3.open(std::string(config) + std::string("input3.txt"), std::ios::in);
        if (!File3)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            int first_mul = 0;
            first_mul = task3(File3);
            std::cout << "Result Part1:" << first_mul << std::endl;
            std::cout << "Result Part2 " << task3Prim(File3, first_mul) << std::endl;
        }
        File3.close();
        std::cout << "File is closed correctly " << std::endl;
    }
    break;
    case 4:
    {
        std::fstream File4;
        std::cout << "Task4 -> Passport Processing" << std::endl;
        File4.open(std::string(config) + std::string("input4.txt"), std::ios::in);
        if (!File4)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Result Part1: Number of valid passport: " << std::endl
                      << task4(File4) << std::endl;
            File4.close();
            File4.open(std::string(config) + std::string("input4.txt"), std::ios::in);
            std::cout << "Result Part2: Number of valid passport: " << std::endl
                      << task4_prim(File4) << std::endl;
            File4.close();
            std::cout << "File is closed correctly " << std::endl;
        }
    }
    break;
    case 5:
    {
        std::fstream File5;
        std::cout << "Task5 -> Binary Boarding" << std::endl;
        File5.open(std::string(config) + std::string("input5.txt"), std::ios::in);
        if (!File5)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Result: Max seat_ID: " << std::endl
                      << task5(File5) << std::endl;
            File5.close();
            std::cout << "File is closed correctly " << std::endl;
        }
    }
    break;
    case 6:
    {
        std::fstream File6;
        std::cout << "Task6 -> Custom Customs" << std::endl;
        File6.open(std::string(config) + std::string("input6.txt"), std::ios::in);
        if (!File6)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "Result: " << task6(File6) << std::endl;
            File6.close();
            std::cout << "File is closed correctly " << std::endl;
        }
    }
    break;
    case 7:
    {
        std::cout << "Task7 -> Handy Haversacks" << std::endl;
        std::fstream File7;
        File7.open(std::string(config) + std::string("input7.txt"), std::ios::in);
        if (!File7)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "It doesnt work now, I am planning do it in the near future ;)" << std::endl;
            File7.close();
            std::cout << "File is closed correctly " << std::endl;
        }
    }
    break;
    case 8:
    {
        std::cout << "Task8 -> Handheld Halting" << std::endl;
        std::fstream File8;
        File8.open(std::string(config) + std::string("input8.txt"), std::ios::in);
        if (!File8)
        {
            std::cout << "Error, incorrect opening file!" << std::endl;
            return -1;
        }
        else
        {
            //std::cout << "Result: " << task8(File8) << std::endl;
            File8.close();
            std::cout << "It doesnt work now, I am planning do it in the near future ;)" << std::endl;
            std::cout << "File is closed correctly " << std::endl;
        }
    }
    break;
    case 9:
    {
        std::cout << "Podziel hex stringa na 2 bajtowe chunks " << std::endl;
        std::string text = "23D923C2FCCBF3D385BC067FD56C974218B83BD944575B80D700B9362FCD15EC3CD07B9664247DACE7479AD413DA4AF8B0038F093C39B20286821331D0D24B70E277C108AB4A7D667334C991839F6FA13F5F23F1D4A3A4C57D8387E138DE65895A74427CBB47004741EA80BDC103D5AE7083CDEFA9EF89EA8AE0A8236E8F676FCC23C8EAC0D74DEF4AE17AF7F8E7D5147B1F177290650C7F9CA9D01BFB6F2568740963479B9A3D5DC27EBB21B9C2F75CCD617DBF68F389619E6C210C0FD5DFACC08B9A1B57071FB75984B09BDDDE984A22F5E16A4AF031E4FB29A6DD1BF059A23619168988D6F94A95B2A746DC29818101D4664F5612B2689BB56CE1B664EE4C";
        std::cout << "przykladowy string: " << text << std::endl;
        split_string(text);
    }
    break;
    default:
    {
        std::cout << "Default" << std::endl;
    }
    }
    return 0;
}