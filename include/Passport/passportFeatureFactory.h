#pragma once

#include <memory>
#include <functional>
#include "passportFeatureStrategy.h"
#include "passportFeatures.h"

class PassportFeatureFactory
{
public:
    PassportFeatureFactory();
    std::unique_ptr<PassportFeatureStrategy> getFeature(const std::string &featureKey, const std::string &value);

private:
    typedef std::function<std::unique_ptr<PassportFeatureStrategy>(const std::string &in)> creationMethod;
    std::unordered_map<std::string, creationMethod> features;

    void initializeFeatureMap();
    void handleNonExistFeature(const std::unordered_map<std::string, creationMethod>::iterator &it);

    std::unique_ptr<PassportFeatureStrategy> getBirthYear(const std::string &input);
    std::unique_ptr<PassportFeatureStrategy> getIssueYear(const std::string &input);
    std::unique_ptr<PassportFeatureStrategy> getExpirationYear(const std::string &input);
    std::unique_ptr<PassportFeatureStrategy> getHeight(const std::string &input);
    std::unique_ptr<PassportFeatureStrategy> getHairColor(const std::string &input);
    std::unique_ptr<PassportFeatureStrategy> getEyeColor(const std::string &input);
    std::unique_ptr<PassportFeatureStrategy> getPassportID(const std::string &input);
    std::unique_ptr<PassportFeatureStrategy> getCertificateID(const std::string &input);
};