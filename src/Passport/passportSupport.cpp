#include "../../include/Passport/passport.h"

Passport::Passport(std::shared_ptr<PassportFeatureFactory> featureFactoryPara, const std::string &input) : featureFactory(featureFactoryPara)
{
    getFeatures(input);
}

bool Passport::isValid()
{
    for (auto &feature : features)
    {
        if (!feature->isValid())
        {
            return false;
        }
    }
    return true;
}

void Passport::getFeatures(const std::string &nameOfFeature)
{
    std::string residue = nameOfFeature;
    uint32_t length = static_cast<uint32_t>(residue.find(" "));
    while (residue.size() != 0)
    {
        parseKeyValue(residue.substr(0, length));
        residue.erase(0, length + 1);
        length= static_cast<uint32_t>(residue.find(" "));
        if (length == std::string::npos)
        {
            length = static_cast<uint32_t>(residue.size());
        }
    }
}

void Passport::parseKeyValue(const std::string &keyFromInput)
{
    std::string key = keyFromInput.substr(0, 3);
    std::string value = keyFromInput.substr(4, std::string::npos);
    auto strategy = featureFactory->getFeature(key, value);
    features.push_back(std::move(strategy));
}

std::vector<std::string> parseForNewPassport(std::fstream &file)
{
	std::string line, passport = "";
	std::vector<std::string> passportData;
	while (getline(file, line))
	{
		if (!line.empty())
		{
			passport += line + " ";
		}
		else
		{
			passportData.emplace_back(std::move(passport));
			passport = "";
		}
	}
	passportData.emplace_back(std::move(passport));
	return passportData;
}