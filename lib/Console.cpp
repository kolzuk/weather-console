#include "Console.h"

#include <iostream>
#include <iomanip>

const uint8_t MORNING_TIME = 8;
const uint8_t DAY_TIME = 12;
const uint8_t EVENING_TIME = 18;
const uint8_t NIGHT_TIME = 0;

void Console::Print(const json& data, uint16_t forecast_days, const std::string& city_name, const std::string& country_name) {
    system("cls");
    std::cout << "Weather forecast: " << city_name << ", " << country_name <<  std::endl;
    std::cout << std::endl;
    std::cout << "Temperature: " << data.at("current_weather").at("temperature") << " °C" << std::endl ;
    std::cout << "Windspeed: " << data.at("current_weather").at("windspeed") << " km/h" << std::endl;
    std::cout << "Winddirection: " << data.at("current_weather").at("winddirection") << "°" << std::endl;
    for (uint16_t i = 0; i < forecast_days; ++i) {
        PrintOneDay(data, i, city_name);
    }
}

void Console::PrintOneDay(const json& data, uint16_t number_of_day, const std::string& city_name) {
    std::string date = data.at("daily").at("time")[number_of_day];

    try {
        float morning_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + MORNING_TIME];
        float morning_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + MORNING_TIME];
        uint16_t morning_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + MORNING_TIME];
        float morning_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + MORNING_TIME];
        uint16_t morning_precipitation_probability =
            data.at("hourly").at("precipitation_probability")[number_of_day * 24 + MORNING_TIME];

        float day_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + DAY_TIME];
        float day_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + DAY_TIME];
        uint16_t day_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + DAY_TIME];
        float day_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + DAY_TIME];
        uint16_t day_precipitation_probability =
            data.at("hourly").at("precipitation_probability")[number_of_day * 24 + DAY_TIME];

        float evening_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + EVENING_TIME];
        float evening_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + EVENING_TIME];
        uint16_t evening_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + EVENING_TIME];
        float evening_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + EVENING_TIME];
        uint16_t evening_precipitation_probability =
            data.at("hourly").at("precipitation_probability")[number_of_day * 24 + EVENING_TIME];

        float night_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + NIGHT_TIME];
        float night_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + NIGHT_TIME];
        int night_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + NIGHT_TIME];
        float night_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + NIGHT_TIME];
        float night_precipitation_probability =
            data.at("hourly").at("precipitation_probability")[number_of_day * 24 + NIGHT_TIME];
    } catch(...) {
        std::cerr << "No data for these day: " << date << std::endl;
        std::cerr << std::endl;
        return;
    }

    float morning_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + MORNING_TIME];
    float morning_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + MORNING_TIME];
    uint16_t morning_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + MORNING_TIME];
    float morning_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + MORNING_TIME];
    uint16_t morning_precipitation_probability =
        data.at("hourly").at("precipitation_probability")[number_of_day * 24 + MORNING_TIME];

    float day_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + DAY_TIME];
    float day_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + DAY_TIME];
    uint16_t day_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + DAY_TIME];
    float day_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + DAY_TIME];
    uint16_t day_precipitation_probability =
        data.at("hourly").at("precipitation_probability")[number_of_day * 24 + DAY_TIME];

    float evening_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + EVENING_TIME];
    float evening_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + EVENING_TIME];
    uint16_t evening_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + EVENING_TIME];
    float evening_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + EVENING_TIME];
    uint16_t evening_precipitation_probability =
        data.at("hourly").at("precipitation_probability")[number_of_day * 24 + EVENING_TIME];

    float night_temperature = data.at("hourly").at("temperature_120m")[number_of_day * 24 + NIGHT_TIME];
    float night_windspeed = data.at("hourly").at("windspeed_120m")[number_of_day * 24 + NIGHT_TIME];
    int night_winddirection = data.at("hourly").at("winddirection_120m")[number_of_day * 24 + NIGHT_TIME];
    float night_precipitation = data.at("hourly").at("precipitation")[number_of_day * 24 + NIGHT_TIME];
    float night_precipitation_probability =
        data.at("hourly").at("precipitation_probability")[number_of_day * 24 + NIGHT_TIME];

    std::cout << "                                                     ┏━━━━━━━━━━┓" << std::endl; // 14x3 - SizeOfTitleBlock
    std::cout << "    ┏━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━┫"<<date<<"┣━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "    ┃        Morning        ┃          Day           ┣━━━━━━━━━━┫        Evening       ┃          Night          ┃" << std::endl;
    std::cout << "    ┣━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━┫" << std::endl;
    std::cout << "    ┃ Temperature: " << std::setw(6) <<  morning_temperature << " °C┃ Temperature: " << std::setw(7) <<  day_temperature << " °C┃          ┃ Temperature: " << std::setw(5) << evening_temperature << " °C┃ Temperature: " << std::setw(8) <<  night_temperature << " °C┃" << std::endl;
    std::cout << "    ┃ Windspeed:   " << std::setw(4) <<  morning_windspeed << " km/h┃ Windspeed:   " << std::setw(5) <<  day_windspeed << " km/h┃          ┃ Windspeed: " << std::setw(5) << evening_windspeed << " km/h┃ Windspeed:   " << std::setw(6) <<  night_windspeed << " km/h┃" << std::endl;
    std::cout << "    ┃ Wind Direc.: " << std::setw(8) <<  morning_winddirection << "°┃ Wind Direc.: " << std::setw(9) <<  day_winddirection << "°┃          ┃ Wind Direc.: " << std::setw(7) << evening_winddirection << "°┃ Wind Direc.: " << std::setw(10) <<  night_winddirection << "°┃" << std::endl;
    std::cout << "    ┃ Precipitation:" << std::setw(5) <<  morning_precipitation << " mm┃ Precipitation:" << std::setw(6) <<  day_precipitation << " mm┃          ┃ Precipitation:" << std::setw(4) << evening_precipitation << " mm┃ Precipitation:" << std::setw(7) <<  night_precipitation << " mm┃" << std::endl;
    std::cout << "    ┃ Prec. Prob.: " << std::setw(7) <<  morning_precipitation_probability << " %┃ Prec. Prob.: " << std::setw(8) <<  day_precipitation_probability << " %┃          ┃ Prec. Prob.: " << std::setw(6) << evening_precipitation_probability << " %┃ Prec. Prob.: " << std::setw(9) <<  night_precipitation_probability << " %┃" << std::endl;
    std::cout << "    ┗━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
    std::cout << std::endl;
}

