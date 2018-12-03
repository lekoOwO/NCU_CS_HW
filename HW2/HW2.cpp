/**
    1071_CS_HW2_107501006.cpp

    @author Rex Tseng
    @version 1.0 03/10/2018
*/
#include <iostream>
#include <regex>
#include <string>
#include "date.h"

int main() {
    std::string input;
    std::smatch sm;
    std::cout << "Please input a date (e.g. 5/20): ";
    getline(std::cin, input);
    if (std::regex_match(
            input, sm,
            std::regex("(?:.*?)(\\d{1,2})(?:.*)/(?:.*?)(\\d{1,2})(?:.*)"))) {
        auto d = date::year{2018} / stoi(sm[1]) / stoi(sm[2]);

        if (!d.ok()) {
            std::cout << "Invalid date!" << std::endl;
            return 87;
        }
        std::cout << sm[1] << "/" << sm[2];
        to_stream(std::cout, " is %A\n", date::weekday{d});
        return 0;
    } else {
        std::cout << "Invalid input!" << std::endl;
        return 87;
    }
}