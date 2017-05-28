#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <json.hpp>
#include <fstream>
#include "ConfigurationValidator.h"

using json = nlohmann::json;


    /*!
     * Configuration read statuses
     */
enum class ConfigurationStatus {
    ReadSuccess,
    ReadError,
    ParseError,
    WriteSuccess,
    WriteError
};


class Configuration {
private:
    json config;
    static void overrideLevel(json &config, const json &other, std::string path = "");
    std::shared_ptr<ConfigurationValidator> validator;
public:
    Configuration(std::shared_ptr<ConfigurationValidator> validator = nullptr) : validator(validator) {};
    Configuration(json &config, std::shared_ptr<ConfigurationValidator> validator = nullptr) : config(config), validator(validator) {};
    /*!
     * @brief Tries to load the specified json file
     * @param file - the file to load
     * @return read status
     */
    ConfigurationStatus loadConfigFile(const std::string &file);
    void validateAndFix();
    ConfigurationStatus writeConfig(const std::string &file);
    void overrideConfig(const json &other);
    const json& getConfig() { return config; };
    /*!
     * @brief Tries to load the specified json file into @a config
     * @param file - the file to load
     * @param config - into what to load
     * @return read status, see ConfigurationReadStatus
     */
    ConfigurationStatus loadConfigFile(const std::string &file, json &config);
    static void validateAndFix(const ConfigurationValidator &validator, json &config);
    static ConfigurationStatus writeConfig(const std::string &file, const json &config);
    static void overrideConfig(json &config, const json &other, std::shared_ptr<ConfigurationValidator> validator = nullptr);

    template<typename T, std::size_t n>
    const json& operator[](T (&key)[n]) const {
        return config.operator[](key);
    }
};

#endif
