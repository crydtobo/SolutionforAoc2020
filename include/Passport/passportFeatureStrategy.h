#pragma once

class PassportFeatureStrategy{
    public:
        virtual bool isValid() = 0;
        virtual ~PassportFeatureStrategy() = default;
};
