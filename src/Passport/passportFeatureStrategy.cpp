#include <iostream>
#include <exception>
#include <vector>
#include <regex>

#include "../../include/Passport/passportFeatureStrategy.h"
#include "../../include/Passport/passportFeatures.h"

namespace
{
    const unsigned int MIN_BIRTH_YEAR = 1920;
    const unsigned int MAX_BIRTH_YEAR = 2002;
    const unsigned int MIN_ISSUE_YEAR = 2010;
    const unsigned int MAX_ISSUE_YEAR = 2020;
    const unsigned int MIN_EXPIRATION_YEAR = 2020;
    const unsigned int MAX_EXPIRATION_YEAR = 2030;
    const unsigned int MIN_HEIGHT_CM = 150;
    const unsigned int MAX_HEIGHT_CM = 193;
    const unsigned int MIN_HEIGHT_IN = 59;
    const unsigned int MAX_HEIGHT_IN = 76;
    const std::vector<std::string> POSSIBLE_EYE_COLORS{"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
}

BirthYear::BirthYear(const std::string &input)
{
    this->birthYear = std::stoi(input);
}

bool BirthYear::isValid()
{
    return birthYear >= MIN_BIRTH_YEAR && birthYear <= MAX_BIRTH_YEAR;
}

IssueYear::IssueYear(const std::string &input)
{
    this->issueYear = std::stoi(input);
}

bool IssueYear::isValid()
{
    return issueYear >= MIN_ISSUE_YEAR && issueYear <= MAX_ISSUE_YEAR;
}

ExpirationYear::ExpirationYear(const std::string &input)
{
    this->expirationYear = std::stoi(input);
}

bool ExpirationYear::isValid()
{
    return expirationYear >= MIN_EXPIRATION_YEAR && expirationYear <= MAX_EXPIRATION_YEAR;
}

Height::Height(const std::string &input) : height(input)
{
    initializeMapUnit();
}

void Height::initializeMapUnit()
{
    checkUnitHeight cmCheckFun = std::bind(&Height::checkHeightCm, this, std::placeholders::_1);
    units.emplace("cm", cmCheckFun);
    checkUnitHeight inCheckFun = std::bind(&Height::checkHeightIn, this, std::placeholders::_1);
    units.emplace("in", inCheckFun);
}

bool Height::checkisNumberHeight(const std::string &height)
{
    std::regex e("^-?\\d+");
    if (std::regex_match(height, e))
        return true;
    return false;
}

bool Height::isValid()
{
    std::string unit = getUnit();
    if(checkisNumberHeight(unit))
        return false;
    uint32_t value = getHeightVal();
    return checkHeightVal(unit, value);
}

bool Height::checkHeightVal(const std::string &unit, uint32_t heightVal)
{
    auto it = units.find(unit);
    handleNonExistUnit(it);
    return it->second(heightVal);
}

void Height::handleNonExistUnit(const std::unordered_map<std::string, checkUnitHeight>::iterator &it)
{
    if (it == units.end())
    {
        throw std::runtime_error("non-existent height unit");
    }
}

std::string Height::getUnit()
{
    if (height.empty())
    {
        throw std::runtime_error("Problem with height input");
    }
    std::string unit = height.substr(height.size() - 2, height.size());
    return unit;
}

uint32_t Height::getHeightVal()
{
    std::string extractedVal = height.substr(0, height.size() - 2);
    return std::stoi(extractedVal);
}

bool Height::checkHeightCm(uint32_t heightVal)
{
    return heightVal >= MIN_HEIGHT_CM && heightVal <= MAX_HEIGHT_CM;
}

bool Height::checkHeightIn(uint32_t heightVal)
{
    return heightVal >= MIN_HEIGHT_IN && heightVal <= MAX_HEIGHT_IN;
}

HairColor::HairColor(const std::string &input) : hairColor(input) {}

bool HairColor::isValid()
{
    return isValidMarker() && isValidValue();
}

bool HairColor::isValidMarker()
{
    return hairColor[0] = '#';
}

bool HairColor::isValidValue()
{
    std::string value = hairColor.substr(1, hairColor.size());
    return value.size() == 6;
}

EyeColor::EyeColor(const std::string &input) : eyeColor(input) {}

bool EyeColor::isValid()
{
    auto it = std::find(POSSIBLE_EYE_COLORS.begin(), POSSIBLE_EYE_COLORS.end(), eyeColor);
    return it != POSSIBLE_EYE_COLORS.end();
}

PassportID::PassportID(const std::string &input) : passportId(input) {}

bool PassportID::isValid()
{
    return isValidLength() && isNumberOnly();
}

bool PassportID::isValidLength()
{
    return passportId.size() == 9;
}

bool PassportID::isNumberOnly()
{
    auto notNumberFound = std::find_if(passportId.begin(), passportId.end(), [](char c)
                                       { return std::isdigit(c) == 0; });
    return notNumberFound == passportId.end();
}