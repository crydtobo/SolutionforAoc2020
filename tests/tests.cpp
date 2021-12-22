#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <optional>

#include "../include/tasks.h"
#include "../include/solution.h"
 
const std::string test0 = "ecl:tr# pid:834567 eyr:1234 hcl:#fffffd byr:1909 iyr:2007 cid:123 hgt:163cm";
const std::string test1 = "ecl:gry pid:860033327 eyr:2020 hcl:#fffffd byr:1937 iyr:2017 cid:147 hgt:183cm";
const std::string test2 = "iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884 hcl:#cfa07d byr:1929 hgt:181in";
const std::string test3 = "hcl:#ae17e1 iyr:2013 eyr:2024 ecl:brn pid:760753108 byr:1931 hgt:179cm";
const std::string test4 = "ecl:gry pid:866542327 eyr:2002 hcl:#feadfd byr:1930 iyr:2017 cid:144 hgt:153cm";
const std::string test5 = "hcl:#cfa07d eyr:2025 pid:166559648 cid:147 hgt:183cm";
const std::string test6 = "ecl:gry cid:147 hgt:183cm";
const std::string test7 = "ecl:gry cid:147 hgt:183cm iyr:2011 ecl:brn";

TEST(test, encode_tag)
{
    std::vector<uint8_t> encoded, encoded1, encoded2, encoded3;
    bool state;
    encodeTag(encoded, ASN1_Tag::UNIVERSAL, ASN1_Tag::OCTET_STRING);
    state = encoded[0] == 0x04 ? 1 : 0;
    ASSERT_TRUE(state);
    encodeTag(encoded1, ASN1_Tag::UNIVERSAL, ASN1_Tag::BIT_STRING);
    state = encoded1[0] == 0x03 ? 1 : 0;
    ASSERT_TRUE(state);
    encodeTag(encoded2, ASN1_Tag::UNIVERSAL, ASN1_Tag::INTEGER);
    state = encoded2[0] == 0x02 ? 1 : 0;
    ASSERT_TRUE(state);
    encodeTag(encoded3, ASN1_Tag::UNIVERSAL, ASN1_Tag::NULL_TAG);
    state = encoded3[0] == 0x05 ? 1 : 0;
    ASSERT_TRUE(state);
}

TEST(test, isEven)
{
    ASSERT_TRUE(isEven(2));
    ASSERT_TRUE(isEven(4));
    ASSERT_TRUE(isEven(6));
    ASSERT_TRUE(isEven(13) == false);
    ASSERT_TRUE(isEven(25) == false);
}

TEST(test, isProperlyPass)
{
    ASSERT_TRUE(isProperlyPass(2, 1, 5));
    ASSERT_TRUE(isProperlyPass(12, 10, 34));
    ASSERT_TRUE(isProperlyPass(7, 1, 5) == false);
    ASSERT_TRUE(isProperlyPass(12, 15, 20) == false);
    ASSERT_TRUE(isProperlyPass(20, 0, 15) == false);
    ASSERT_TRUE(isProperlyPass(2019, 1000, 2020));
}

TEST(test, isprobablyCorrectPassword)
{
    ASSERT_TRUE(isprobablyCorrectPassword(1, 2));
    ASSERT_TRUE(isprobablyCorrectPassword(10, 11));
    ASSERT_TRUE(isprobablyCorrectPassword(10222, 10223));
    ASSERT_TRUE(isprobablyCorrectPassword(4, 5));
    ASSERT_TRUE(isprobablyCorrectPassword(7, 5) == false);
    ASSERT_TRUE(isprobablyCorrectPassword(12,0) == false);
    ASSERT_TRUE(isprobablyCorrectPassword(20, 15) == false);
    ASSERT_TRUE(isprobablyCorrectPassword(2019, 20212321) == false);
}

TEST(test, isCorrectBasicPassport)
{
    ASSERT_TRUE(isCorrectBasicPassport(test0));
    ASSERT_TRUE(isCorrectBasicPassport(test1));
    ASSERT_TRUE(isCorrectBasicPassport(test2));
    ASSERT_TRUE(isCorrectBasicPassport(test4));
    ASSERT_TRUE(isCorrectBasicPassport(test3) == false);
    ASSERT_TRUE(isCorrectBasicPassport(test5) == false);
    ASSERT_TRUE(isCorrectBasicPassport(test6) == false);
    ASSERT_TRUE(isCorrectBasicPassport(test7) == false);   
}

TEST(test, findHashFirst)
{
    ASSERT_TRUE(findHashFirst(test0, 70));
    ASSERT_TRUE(findHashFirst(test1, 8));
    ASSERT_TRUE(findHashFirst(test2, 72));
    ASSERT_TRUE(findHashFirst(test3, 50));
    ASSERT_TRUE(findHashFirst(test4, 60));
    ASSERT_TRUE(findHashFirst(test5, 50));
    ASSERT_TRUE(findHashFirst(test6, 14));
    ASSERT_TRUE(findHashFirst(test3, 432) == false);
    ASSERT_TRUE(findHashFirst(test5, 89) == false);
    ASSERT_TRUE(findHashFirst(test6, 200) == false);
    ASSERT_TRUE(findHashFirst(test7, 120) == false);
}

TEST(test, findHashSecond)
{
    ASSERT_TRUE(findHashSecond(test0, 75));
    ASSERT_TRUE(findHashSecond(test1, 80));
    ASSERT_TRUE(findHashSecond(test2, 79));
    ASSERT_TRUE(findHashSecond(test3, 100));
    ASSERT_TRUE(findHashSecond(test4, 79));
    ASSERT_TRUE(findHashSecond(test5, 100));
    ASSERT_TRUE(findHashSecond(test6, 25));
    ASSERT_TRUE(findHashSecond(test3, 23) == false);
    ASSERT_TRUE(findHashSecond(test5, 4) == false);
    ASSERT_TRUE(findHashSecond(test6, 12) == false);
    ASSERT_TRUE(findHashSecond(test7, 15) == false);
}

TEST(test, everyNumberHash)
{
    ASSERT_TRUE(everyNumberHash(test0, 2, 3));
    ASSERT_TRUE(everyNumberHash(test1, 5, 7));
    ASSERT_TRUE(everyNumberHash(test2, 12, 1) == false);
    ASSERT_TRUE(everyNumberHash(test3, 2, 1) == false);
    ASSERT_TRUE(everyNumberHash(test5, 4, 2) == false);
    ASSERT_TRUE(everyNumberHash(test6, 1 ,3 ) == false);
    ASSERT_TRUE(everyNumberHash(test7, 1, 1) == false);
}

TEST(test, everySecondLevel)
{
    ASSERT_TRUE(everySecondLevel(10));
    ASSERT_TRUE(everySecondLevel(1240024));
    ASSERT_TRUE(everySecondLevel(2));
    ASSERT_TRUE(everySecondLevel(46));
    ASSERT_TRUE(everySecondLevel(12401080));
    ASSERT_TRUE(everySecondLevel(1674850));
    ASSERT_TRUE(everySecondLevel(4026));
    ASSERT_TRUE(everySecondLevel(0) == false);
    ASSERT_TRUE(everySecondLevel(23) == false);
    ASSERT_TRUE(everySecondLevel(21231289) == false);
    ASSERT_TRUE(everySecondLevel(9092453) == false);
    ASSERT_TRUE(everySecondLevel(3) == false);
}

TEST(test, acceptedPassword)
{
    ASSERT_TRUE(acceptedPassword(3));
    ASSERT_TRUE(acceptedPassword(1));
    ASSERT_TRUE(acceptedPassword(0) == false);
    ASSERT_TRUE(acceptedPassword(23) == false);
    ASSERT_TRUE(acceptedPassword(21231289) == false);
    ASSERT_TRUE(acceptedPassword(9092453) == false);
    ASSERT_TRUE(acceptedPassword(22) == false);
    ASSERT_TRUE(acceptedPassword(33) == false);
    ASSERT_TRUE(acceptedPassword(11) == false);
    ASSERT_TRUE(acceptedPassword(21231289) == false);
    ASSERT_TRUE(acceptedPassword(9092453) == false);
}

TEST(test, task1ForInput1)
{
    std::fstream file;
    const std::string filename = "input1.txt";

    openFile(file, filename);
    ASSERT_TRUE(task1(file) == 719796);
    file.close();

    openFile(file, filename);
    ASSERT_TRUE(task1Prim(file) == 144554112);
    file.close();
}

TEST(test, task2ForInput2)
{
    std::fstream file;
    const std::string filename = "input2.txt";

    openFile(file, filename);
    ASSERT_TRUE(task2(file) == 434);
    file.close();

    openFile(file, filename);
    ASSERT_TRUE(task2Prim(file) == 509);
    file.close();
}

TEST(test, task3ForInput3)
{
    std::fstream file;
    const std::string filename = "input3.txt";

    openFile(file, filename);
    int resultTask3 = task3(file);
    ASSERT_TRUE(resultTask3 == 47);
    file.close();

    openFile(file, filename);
    ASSERT_TRUE( task3Prim(file, resultTask3)  == 3819182400);
    file.close();
}

TEST(test, task4ForInput4)
{
    std::fstream file;
    const std::string filename = "input4.txt";

    openFile(file, filename);
    ASSERT_TRUE(task4(file) == 210);
    file.close();

    openFile(file, filename);
    ASSERT_TRUE( task4Prim(file)  == 131);
    file.close();
}

TEST(test, task5ForInput5)
{
    std::fstream file;
    const std::string filename = "input5.txt";

    openFile(file, filename);
    ASSERT_TRUE(task5(file) == 539);
    file.close();
}

TEST(test, task6ForInput6)
{
    std::fstream file1;
    const std::string filename = "input6.txt";

    openFile(file1, filename);
    ASSERT_TRUE(task6(file1) == 3276);
    file1.close();
}
