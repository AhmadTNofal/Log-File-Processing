#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// Function to extract and return the log level in uppercase
std::string level(const std::string& logLine) {
    size_t start = logLine.find('[') + 1;
    size_t end = logLine.find(']');

    if (start != std::string::npos && end != std::string::npos && end > start) {
        std::string logLevel = logLine.substr(start, end - start);
        // Convert to uppercase
        std::transform(logLevel.begin(), logLevel.end(), logLevel.begin(), [](unsigned char c) { return std::toupper(c); });
        return logLevel;
    }
    return ""; // Return an empty string if the format is incorrect
}

int main() {
    std::ifstream logFile("log.in"); // Open the log file
    std::string logLine;

    if (logFile.is_open()) {
        while (getline(logFile, logLine)) { // Read each line from the file
            std::string logLevel = level(logLine);
            std::cout << logLevel << std::endl; // Output the extracted log level
        }
        logFile.close(); // Close the file when done
    } else {
        std::cerr << "Unable to open log file" << std::endl; // Error message if the file can't be opened
    }

    return 0;
}
