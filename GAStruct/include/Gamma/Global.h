//
// Created by Deiwid on 2017-01-17.
//

#ifndef GAMMA_GLOBAL_H
#define GAMMA_GLOBAL_H

#include <spdlog/spdlog.h>
#include <json.hpp>
#include "BuildOptions.h"
#include "Configuration.h"
#include "Counter.h"

#define CONFP Global::config
#define CONF (*Global::config)

using json = nlohmann::json;

class Global {
private:
    static std::shared_ptr<spdlog::sinks::sink> stdoutSink;
    static std::shared_ptr<spdlog::sinks::rotating_file_sink_mt> fileSink;
public:
    static std::shared_ptr<Configuration> config;
    static std::shared_ptr<spdlog::logger> Logger;
    static json defaultConfig;
    static Counter objectIds;
    static void initDefaultConfig();
    static void initLogger(spdlog::level::level_enum stdoutLevel = spdlog::level::debug, spdlog::level::level_enum fileLevel = spdlog::level::debug);
    static void applyConfig();
    static void setLogLevel(spdlog::level::level_enum stdoutLevel, spdlog::level::level_enum fileLevel);
    static void destroy();
};

#endif //GAMMA_GLOBAL_H
