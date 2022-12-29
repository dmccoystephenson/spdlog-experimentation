#include <string>
#include <iostream>
#include "../include/myLogger.hpp"


int main() {
    std::string toPrint = "Hello World!";
    
    MyLogger logger("info.log", "error.log");
    logger.info(toPrint);
    return 0;
}