#include "Weather.h"

#include <iostream>

void Weather::IncreaseForecastDays() {
    if (forecast_days == 1) {
        forecast_days = 3;
    } else if (forecast_days == 3) {
        forecast_days = 7;
    } else if (forecast_days == 7) {
        forecast_days = 14;
    } else if (forecast_days == 14) {
        forecast_days = 16;
    } else if (forecast_days == 16) {
        forecast_days = 1;
    }
}

void Weather::DecreaseForecastDays() {
    if (forecast_days == 1) {
        forecast_days = 16;
    } else if (forecast_days == 3) {
        forecast_days = 1;
    } else if (forecast_days == 7) {
        forecast_days = 3;
    } else if (forecast_days == 14) {
        forecast_days = 7;
    } else if (forecast_days == 16) {
        forecast_days = 14;
    }
}

void Weather::IncreaseCityIndex() {
    if (current_city_index != data_config.at("city").size() - 1) {
        current_city_index++;
    } else {
        current_city_index = 0;
    }

    city_name = data_config.at("city")[current_city_index];
    std::replace(city_name.begin(), city_name.end(), ' ', '_');

    std::string api_url = "https://api.api-ninjas.com/v1/city?name=";

    cpr::Response r = cpr::Get(cpr::Url{api_url + city_name},
                               cpr::Header{{"X-Api-Key", "V15dlqGRwjm3q4D2hcBdVw==ETxqG8Cp5jsNsXPu"}});

    json data = json::parse(r.text);

    latitude = data[0].at("latitude");
    longitude = data[0].at("longitude");
    city_name = data[0].at("name");
    country_name = data[0].at("country");
}

void Weather::DecreaseCityIndex() {
    if (current_city_index != 0) {
        current_city_index--;
    } else {
        current_city_index = data_config.at("city").size() - 1;
    }

    city_name = data_config.at("city")[current_city_index];
    std::replace(city_name.begin(), city_name.end(), ' ', '_');

    std::string api_url = "https://api.api-ninjas.com/v1/city?name=";

    cpr::Response r = cpr::Get(cpr::Url{api_url + city_name},
                               cpr::Header{{"X-Api-Key", "V15dlqGRwjm3q4D2hcBdVw==ETxqG8Cp5jsNsXPu"}});

    json data = json::parse(r.text);

    latitude = data[0].at("latitude");
    longitude = data[0].at("longitude");
    city_name = data[0].at("name");
    country_name = data[0].at("country");
}

void Weather::ReadConfig(const std::filesystem::path& path) {
    std::ifstream file(path);

    assert(file.is_open());

    data_config = json::parse(file);

    city_name = data_config.at("city")[current_city_index];
    forecast_days = data_config.at("forecast days");
    update_time = data_config.at("update_time");
}

json Weather::GetRequest() {
    std::string api_url = template_api_url;
    api_url.replace(api_url.find("latitude="),
                    9,
                    "latitude=" + std::to_string(latitude)); // Set Own Latitude
    api_url.replace(api_url.find("longitude="),
                    10,
                    "longitude=" + std::to_string(longitude)); // Set Own Longitude
    cpr::Response r = cpr::Get(cpr::Url{api_url});
    json data = json::parse(r.text);
    return data;
}

uint16_t Weather::GetForecastDays() const {
    return forecast_days;
}

size_t Weather::GetUpdateTime() const {
    return update_time;
}

std::string Weather::GetCityName() const {
    return city_name;
}

std::string Weather::GetCountryName() const {
    return country_name;
}

