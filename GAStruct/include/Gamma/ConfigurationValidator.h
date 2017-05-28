//
// Created by Deiwid on 2017-02-27.
//

#ifndef GAMMA_CONFIGURATIONVALIDATOR_H
#define GAMMA_CONFIGURATIONVALIDATOR_H

#include <json.hpp>

using json = nlohmann::json;

class ConfigurationValidator {
public:
    virtual bool validateAndFix(json &config, bool fix = true) const = 0;
    virtual ~ConfigurationValidator() {}
};

#endif //GAMMA_CONFIGURATIONVALIDATOR_H
