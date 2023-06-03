#pragma once

#include <cstdint>
#include <string>

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Weather {
public:
    void IncreaseForecastDays();
    void DecreaseForecastDays();
    void IncreaseCityIndex();
    void DecreaseCityIndex();
    void ReadConfig(const std::filesystem::path& path);
    json GetRequest();

    [[nodiscard]] uint16_t GetForecastDays() const;
    [[nodiscard]] size_t GetUpdateTime() const;
    [[nodiscard]] std::string GetCityName() const;
    [[nodiscard]] std::string GetCountryName() const;
private:
    // Saint Petersburg Coordinates
    double latitude = 59.95;
    double longitude = 30.3167;
    uint16_t forecast_days = 3;
    uint64_t current_city_index = 0;
    std::string template_api_url = "https://api.open-meteo.com/v1/forecast?latitude=&longitude=&hourly=precipitation_probability,precipitation,windspeed_120m,winddirection_120m,temperature_120m&daily=weathercode,temperature_2m_max,temperature_2m_min,precipitation_sum,windspeed_10m_max&current_weather=true&forecast_days=16&timezone=Europe%2FMoscow";
    std::string city_name = "Saint Petersburg";
    std::string country_name = "RU";
    json data_config;
    size_t update_time;
};
