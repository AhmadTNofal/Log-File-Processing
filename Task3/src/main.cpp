#include "log.hpp"
#include <iostream>

int main() {
    Log log;

    // Attempt to open the log file
    if (!log.create_log("log.in")) {
        std::cerr << "Failed to open log file." << std::endl;
        return 1; // Exit the program if the log file cannot be opened
    }

    // Process each log entry in the file
    while (log.next()) {
        std::string reformatted = log.reformat();  // Get the reformatted log entry
        std::string line = log.line();             // Get the log message
        std::string level = log.level();           // Get the log level

        //Print the reformatted log entry, original log message, and log level
        std::cout << reformatted << std::endl;
        std::cout << line << std::endl;
        std::cout << level << std::endl;
    }

    return 0;
}
