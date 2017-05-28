//
// Created by deiwid on 1/22/17.
//

#ifndef GAMMA_UTILS_H
#define GAMMA_UTILS_H


#include <vector>
#include <set>
#include <vulkan/vulkan.hpp>
#include <sstream>
#include <iomanip>
#include <json.hpp>
#include "Global.h"


using json = nlohmann::json;

#ifdef WIN32
    #ifndef __FILENAME_NO_PROC__
    // Skipping strrchr(__FILE__,'\\') == nullptr check, as VS almost always puts an absolute path
    #define __FILENAME__ (strrchr(__FILE__,'\\')+1)
    #else
    #define __FILENAME__ __FILE__
    #endif
#endif


#define LOGGER Global::Logger
#define LOGT(fmt, ...) Global::Logger->trace("[{}:{}:{}] " fmt, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
#define LOGD(fmt, ...) Global::Logger->debug("[{}:{}:{}] " fmt, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
#define LOGI(fmt, ...) Global::Logger->info("[{}:{}:{}] " fmt, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
#define LOGW(fmt, ...) Global::Logger->warn("[{}:{}:{}] " fmt, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
#define LOGE(fmt, ...) Global::Logger->error("[{}:{}:{}] " fmt, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)
#define LOGC(fmt, ...) Global::Logger->critical("[{}:{}:{}] " fmt, __FILENAME__, __func__, __LINE__, ##__VA_ARGS__)

class Utils {
public:
template<typename S, typename D>
    static void insert(const S &src, D &dest);
    static void insertJsonArray(const json &src, std::set<std::string> &dest);
    static void insertJsonArray(const json &src, std::vector<std::string> &dest);
template<typename T>
    static std::vector<T> toVector(const std::set<T> &src);
    static void remove(std::vector<std::string> &from, const std::vector<std::string> &what);
    static std::string toString(const vk::ApplicationInfo &appInfo, int tabcount = 0, bool noFirstIndent = false);
    static std::string toString(const vk::InstanceCreateInfo &instanceCreateInfo, int tabcount = 0, bool noFirstIndent = false);
    static std::string toString(const vk::DeviceQueueCreateInfo &deviceQueueCreateInfo, int tabcount = 0, bool noFirstIndent = false);
    static std::string toString(const vk::DeviceCreateInfo &deviceCreateInfo, int tabcount = 0, bool noFirstIndent = false);
    static std::string toString(const vk::SwapchainCreateInfoKHR &swapchainCreateInfo, int tabcount = 0, bool noFirstIndent = false);
    static std::string toString(const vk::PhysicalDeviceFeatures &deviceFeatures, int tabcount = 0, bool noFirstIndent = false);
    static std::string toString(const vk::Extent2D &extent2D, int tabcount = 0, bool noFirstIndent = false);
    static std::string createIndent(const int tabCount = 1, const char c = ' ');
    static std::string decodeVulkanVersion(const uint32_t version);
    static std::string toLower(const std::string &str);
    static std::string toUpper(const std::string &str);
    static spdlog::level::level_enum stringLogLevelToEnum(const std::string &lvl);
template<typename T>
    static std::string toString(const std::vector<T> &list, int tabcount = 0);
template<typename T>
    static std::string toString(const T *list, uint32_t size, int tabcount = 0);
    static std::vector<char> loadFile(const std::string &filePath);
    template<typename T, typename... Args>
    static std::unique_ptr<T> make_unique(Args&&... args);
};

template<typename T, typename... Args>
std::unique_ptr<T> Utils::make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<typename S, typename D>
void Utils::insert(const S &src, D &dest) {
    dest.insert(src.begin(), src.end());
}

template<typename T>
std::vector<T> Utils::toVector(const std::set<T> &src) {
    return std::vector<T>(src.begin(), src.end());
}

template<>
std::string Utils::toString(const vk::DeviceQueueCreateInfo *list, uint32_t size, int tabcount);

template<>
std::string Utils::toString(const std::vector<vk::PhysicalDevice> &list, int tabcount);

#define ssi ss << indent
template<typename T>
std::string Utils::toString(const std::vector<T> &list, int tabcount) {
    std::stringstream ss;
    std::string indent = createIndent(tabcount);
    bool first = true;
    for(const T &item : list) {
        if(first) {
            first = false;
        } else {
            ss << ",\n";
        }
        ssi << item;
    }
    return ss.str();
}

template<typename T>
std::string Utils::toString(const T *list, uint32_t size, int tabcount) {
    std::stringstream ss;
    std::string indent = createIndent(tabcount);
    for (uint32_t i = 0; i < size; i++) {
        if (i != 0) {
            ss << ",\n";
        }
        ssi << list[i];
    }
    return ss.str();
}
#undef ssi

#endif //GAMMA_UTILS_H
