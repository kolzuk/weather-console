#include <lib/Console.h>
#include <lib/Weather.h>

#include <iostream>
#include <filesystem>
#include <chrono>
#include <ratio>
#include <thread>

#include <conio.h>
#include <windows.h>

using json = nlohmann::json;

int main(int argc, char** argv) {
    Weather weather;
    weather.ReadConfig(argv[1]);
    json data = weather.GetRequest();

    Console::Print(data, weather.GetForecastDays(), weather.GetCityName(), weather.GetCountryName());
        auto start = std::chrono::system_clock::now();

    while (true) {
        bool flag = false;
        if (GetKeyState(VK_OEM_PLUS) & 0x8000) {
            weather.IncreaseForecastDays();
            flag = true;
        } else if (GetKeyState(VK_OEM_MINUS) & 0x8000) {
            weather.DecreaseForecastDays();
            flag = true;
        } else if (GetKeyState(0x4E) & 0x8000) { // n
            weather.IncreaseCityIndex();
            data = weather.GetRequest();
            flag = true;
        } else if (GetKeyState(0x50) & 0x8000) { // p
            weather.DecreaseCityIndex();
            data = weather.GetRequest();
            flag = true;
        } else if (GetKeyState(VK_ESCAPE) & 0x8000) { // ESCAPE BUTTON
            break;
        }

        auto end = std::chrono::system_clock::now();

        if (std::chrono::duration_cast<std::chrono::seconds>(end - start).count() > weather.GetUpdateTime()) {
            start = std::chrono::system_clock::now();
            flag = true;
        }

        if (flag) {
            Console::Print(data, weather.GetForecastDays(), weather.GetCityName(), weather.GetCountryName());
        }
    }

}