#include "../../include/Passport/passportFeatureFactory.h"

PassportFeatureFactory::PassportFeatureFactory()
{
    initializeFeatureMap();
}

void PassportFeatureFactory::initializeFeatureMap()
{
    creationMethod birthYearFun = std::bind(&PassportFeatureFactory::getBirthYear, this, std::placeholders::_1);
    features.emplace("byr", birthYearFun);

    creationMethod issueYearFun = std::bind(&PassportFeatureFactory::getIssueYear, this, std::placeholders::_1);
    features.emplace("iyr", issueYearFun);

    creationMethod expirationYearFun = std::bind(&PassportFeatureFactory::getExpirationYear, this, std::placeholders::_1);
    features.emplace("eyr", expirationYearFun);

    creationMethod heightFun = std::bind(&PassportFeatureFactory::getHeight, this, std::placeholders::_1);
    features.emplace("hgt", heightFun);

    creationMethod hairColorFun = std::bind(&PassportFeatureFactory::getHairColor, this, std::placeholders::_1);
    features.emplace("hcl", hairColorFun);

    creationMethod eyeColorFun = std::bind(&PassportFeatureFactory::getEyeColor, this, std::placeholders::_1);
    features.emplace("ecl", eyeColorFun);

    creationMethod pidFun = std::bind(&PassportFeatureFactory::getPassportID, this, std::placeholders::_1);
    features.emplace("pid", pidFun);

    creationMethod cidFun = std::bind(&PassportFeatureFactory::getCertificateID, this, std::placeholders::_1);
    features.emplace("cid", cidFun);
}

void PassportFeatureFactory::handleNonExistFeature(const std::unordered_map<std::string, creationMethod>::iterator &it)
{
    if (it == features.end())
    {
        throw std::runtime_error("wrong key - this passport feature does not exist!");
    }
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getFeature(const std::string &featureKeyArg, const std::string &value)
{
    auto iter = features.find(featureKeyArg);
    handleNonExistFeature(iter);
    return iter->second(value);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getBirthYear(const std::string &input)
{
    return std::make_unique<BirthYear>(input);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getIssueYear(const std::string &input)
{
    return std::make_unique<IssueYear>(input);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getExpirationYear(const std::string &input)
{
    return std::make_unique<ExpirationYear>(input);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getHeight(const std::string &input)
{
    return std::make_unique<Height>(input);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getHairColor(const std::string &input)
{
    return std::make_unique<HairColor>(input);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getEyeColor(const std::string &input)
{
    return std::make_unique<EyeColor>(input);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getPassportID(const std::string &input)
{
    return std::make_unique<PassportID>(input);
}

std::unique_ptr<PassportFeatureStrategy> PassportFeatureFactory::getCertificateID(const std::string &input)
{
    return std::make_unique<CertificateID>(input);
}
