#include <string>
#include <iostream>
#include "spdlog/spdlog.h"


int main() {
    std::cout << "Experimenting with the spdlog library!" << std::endl;

    std::cout << "Attempting to use spdlog" << std::endl;
    try {
        auto logger = spdlog::stdout_color_mt("console");
        logger->info("Welcome to spdlog!");
    } catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }

    return 0;
}