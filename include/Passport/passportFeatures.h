#pragma once

#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <functional>

#include <iostream>
#include "passportFeatureStrategy.h"

class BirthYear : public PassportFeatureStrategy
{
public:
    BirthYear(const std::string &input);
    bool isValid() override;

private:
    uint32_t birthYear;
};

class IssueYear : public PassportFeatureStrategy
{
public:
    IssueYear(const std::string &input);
    bool isValid() override;

private:
    uint32_t issueYear;
};

class ExpirationYear : public PassportFeatureStrategy
{
public:
    ExpirationYear(const std::string &input);
    bool isValid() override;

private:
    uint32_t expirationYear;
};

class CertificateID : public PassportFeatureStrategy
{
public:
    CertificateID(const std::string &input)
    {
        this->certificateID = std::stoi(input);
    }

    bool isValid() override
    {
        return true;
    }

private:
    uint32_t certificateID;
};

class Height : public PassportFeatureStrategy
{
public:
    Height(const std::string &input);
    bool isValid() override;

private:
    std::string height;
    typedef std::function<bool(uint32_t)> checkUnitHeight;
    std::unordered_map<std::string, checkUnitHeight> units;

    void initializeMapUnit();
    std::string getUnit();
    uint32_t getHeightVal();
    bool checkHeightVal(const std::string &unit, uint32_t valueOfHeight);
    void handleNonExistUnit(const std::unordered_map<std::string, checkUnitHeight>::iterator &it);
    bool checkHeightCm(uint32_t valueOfHeight);
    bool checkHeightIn(uint32_t valueOfHeight);
    bool checkisNumberHeight(const std::string &height);
};

class HairColor : public PassportFeatureStrategy
{
public:
    HairColor(const std::string &input);
    bool isValid() override;

private:
    std::string hairColor;

    bool isValidMarker();
    bool isValidValue();
};

class EyeColor : public PassportFeatureStrategy
{
public:
    EyeColor(const std::string &input);
    bool isValid() override;

private:
    std::string eyeColor;
};

class PassportID : public PassportFeatureStrategy
{
public:
    PassportID(const std::string &input);
    bool isValid() override;

private:
    std::string passportId;

    bool isValidLength();
    bool isNumberOnly();
};