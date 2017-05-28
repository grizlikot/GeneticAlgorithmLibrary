//
// Created by Deiwid on 2017-02-27.
//

#ifndef GAMMA_GAMMACONFIGURATIONVALIDATOR_H
#define GAMMA_GAMMACONFIGURATIONVALIDATOR_H

#include "ConfigurationValidator.h"

class GammaConfigurationValidator : public ConfigurationValidator {
public:
    bool validateAndFix(json &config, bool fix = true) const override;
};

#endif //GAMMA_GAMMACONFIGURATIONVALIDATOR_H
