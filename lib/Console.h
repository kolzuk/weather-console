#pragma once

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

const uint16_t CONSOLE_WIDTH = 120;
const uint16_t CONSOLE_LENGTH = 30;

class Console {
public:
    static void Print(const json& data, uint16_t forecast_days, const std::string& city_name, const std::string& country_name);
private:
    static void PrintOneDay(const json& data, uint16_t number_of_day, const std::string& city_name);
    static Console console;
    Console() = default;
};

Console Console::console;