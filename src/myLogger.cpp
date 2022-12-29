#include "../include/myLogger.hpp"

MyLogger::MyLogger(std::string ilogname, std::string elogname) {
    // pull in the file & console flags from the environment
    initializeFlagValuesFromEnvironment();
    
    // setup information logger.
    std::vector<spdlog::sink_ptr> infoSinks;
    if (logToFileFlag) {
        infoSinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(ilogname, INFO_LOG_SIZE, INFO_LOG_NUM));
    }
    if (logToConsoleFlag) {
        infoSinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_mt>());
    }
    setInfoLogger(std::make_shared<spdlog::logger>("ilog", begin(infoSinks), end(infoSinks)));
    set_info_level( iloglevel );
    set_info_pattern("[%C%m%d %H:%M:%S.%f] [%l] %v");

    // setup error logger.
    std::vector<spdlog::sink_ptr> errorSinks;
    if (logToFileFlag) {
        errorSinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(elogname, ERROR_LOG_SIZE, ERROR_LOG_NUM));
    }
    if (logToConsoleFlag) {
        errorSinks.push_back(std::make_shared<spdlog::sinks::stdout_sink_mt>());
    }
    setErrorLogger(std::make_shared<spdlog::logger>("elog", begin(errorSinks), end(errorSinks)));
    set_error_level( eloglevel );
    set_error_pattern("[%C%m%d %H:%M:%S.%f] [%l] %v");
}

void MyLogger::set_info_level(spdlog::level::level_enum level) {
    ilogger->set_level( level );
}

void MyLogger::set_error_level(spdlog::level::level_enum level) {
    elogger->set_level( level );
}

void MyLogger::set_info_pattern(const std::string& pattern) {
    ilogger->set_pattern( pattern );
}

void MyLogger::set_error_pattern(const std::string& pattern) {
    elogger->set_pattern( pattern );
}

void MyLogger::info(const std::string& message) {
    ilogger->info(message.c_str());
}

void MyLogger::error(const std::string& message) {
    elogger->error(message.c_str());
}

void MyLogger::trace(const std::string& message) {
    ilogger->trace(message.c_str());
}

void MyLogger::critical(const std::string& message) {
    elogger->critical(message.c_str());
}

void MyLogger::warn(const std::string& message) {
    elogger->warn(message.c_str());
}

void MyLogger::flush() {
    ilogger->flush();
    elogger->flush();
}

void MyLogger::setInfoLogger(std::shared_ptr<spdlog::logger> spdlog_logger) {
    ilogger = spdlog_logger;
}

void MyLogger::setErrorLogger(std::shared_ptr<spdlog::logger> spdlog_logger) {
    elogger = spdlog_logger;
}

void MyLogger::initializeFlagValuesFromEnvironment() {
    std::string logToFileFlagString = getEnvironmentVariable("LOG_TO_FILE");
    std::string logToConsoleFlagString = getEnvironmentVariable("LOG_TO_CONSOLE");
    logToFileFlag = convertStringToBool(logToFileFlagString);
    logToConsoleFlag = convertStringToBool(logToConsoleFlagString);

    if (!logToFileFlag && !logToConsoleFlag) {
        std::cout << "WARNING: LOG_TO_FILE and LOG_TO_CONSOLE are both set to false. No logging will occur." << std::endl;
    }
}

const char* MyLogger::getEnvironmentVariable(std::string variableName) {
    char* variableValue = getenv(variableName.c_str());
    if (variableValue == NULL) {
        return "";
    }
    return variableValue;
}

std::string MyLogger::toLowercase(std::string s) {
    int counter = 0;
    char c;
    while (s[counter]) {
        c = s[counter];
        s[counter] = tolower(c);
        counter++;
    }
    return s;
}

bool MyLogger::convertStringToBool(std::string value) {
    std::string lowercaseValue = toLowercase(value);
    if (lowercaseValue == "true" || lowercaseValue == "1") {
        return true;
    }
    return false;
}