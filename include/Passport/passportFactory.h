#pragma once

#include <memory>
#include <string>

#include "passport.h"
#include "passportFeatureFactory.h"

class PassportFactory
{
public:
    explicit PassportFactory();
    std::unique_ptr<Passport> createPassport(const std::string &input);

private:
    std::shared_ptr<PassportFeatureFactory> featureFactory;
};