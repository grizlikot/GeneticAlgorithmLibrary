//
// Created by Deiwid on 2017-04-07.
//

#ifndef GAMMA_SCENEUPDATE_H
#define GAMMA_SCENEUPDATE_H

#include <cstdint>
#include <string>
#include <array>
#include "Utils.h"

struct SceneUpdate {
    enum Mode {
        fixed,
        locked,
        automatic
    };
    static std::array<std::string, 3> stringVals;
    Mode mode;
    uint32_t rate;
    double period;
    static SceneUpdate parseConfig() {
        SceneUpdate result;
        result.mode = fromString(CONF["scene"]["update"]["mode"]);
        result.rate = CONF["scene"]["update"]["rate"];
        if(result.rate != 0) {
            result.period = 1.0f / result.rate;
        }
        return result;
    }
    static Mode fromString(const std::string &str) {
        std::string low = Utils::toLower(str);
        for(int i=0; i<stringVals.size(); i++) {
            if(low == stringVals[i]) {
                return static_cast<Mode>(i);
            }
        }
        LOGE("Got an invalid scene update mode: {}", str);
        throw std::runtime_error("INVALID_SCENE_UPDATE_MODE");
    }
    static std::string toString(Mode mode) {
        return stringVals[mode];
    }
};

#endif //GAMMA_SCENEUPDATE_H
