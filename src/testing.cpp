#include <string>
#include <iostream>
#include "spdlog/spdlog.h"
#include "../include/myLogger.hpp"


int main() {
    std::cout << "Experimenting with the spdlog library!" << std::endl;

    std::cout << "Attempting to use spdlog" << std::endl;
    try {
        auto logger = spdlog::stdout_color_mt("console");
        logger->info("Welcome to spdlog!");

        logger->info("Creating and using instance of MyLogger");
        std::shared_ptr<MyLogger> myLogger = std::make_shared<MyLogger>("info.log", "error.log");
        myLogger->info("MyLogger instance created");

        for (int i = 1000000; i > 0; i--) { // 1 million
            myLogger->info("Ticks left: " + std::to_string(i));
        }

        logger->info("spdlog version {}  ",  SPDLOG_VERSION);

    } catch (const spdlog::spdlog_ex& ex) {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }

    return 0;
}