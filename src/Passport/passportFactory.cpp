#include "../../include/Passport/passportFactory.h"

PassportFactory::PassportFactory() : featureFactory(std::make_shared<PassportFeatureFactory>()) {}

std::unique_ptr<Passport> PassportFactory::createPassport(const std::string &input)
{
    return std::make_unique<Passport>(featureFactory, input);
}