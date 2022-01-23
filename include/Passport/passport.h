#pragma once 

#include <string>
#include <memory>
#include <vector>
#include <fstream>

#include "passportFeatureFactory.h"
#include "passportFeatureStrategy.h"

class Passport
{
public:
    Passport(std::shared_ptr<PassportFeatureFactory> featureFactory, const std::string &input);

    bool isValid();

private:
    std::shared_ptr<PassportFeatureFactory> featureFactory;
    std::vector<std::unique_ptr<PassportFeatureStrategy>> features;

    void getFeatures(const std::string &nameOfFeature);
    void parseKeyValue(const std::string &key);
};

std::vector<std::string> parseForNewPassport(std::fstream &file);