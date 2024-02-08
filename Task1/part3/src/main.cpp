#include <iostream>
#include <fstream>
#include <string>

// Function to reformat the log line, putting the message first and the log level in parentheses
std::string reformat(const std::string& logLine) {
    size_t start = logLine.find('[') + 1;
    size_t end = logLine.find(']');
    size_t messageStart = logLine.find(": ") + 2;

    if (start != std::string::npos && end != std::string::npos && messageStart != std::string::npos) {
        std::string logLevel = logLine.substr(start, end - start);
        std::string message = logLine.substr(messageStart);

        return message + " (" + logLevel + ")";
    }
    return ""; // Return an empty string if the format is incorrect
}

int main() {
    std::ifstream logFile("log.in"); // Open the log file
    std::string logLine;

    if (logFile.is_open()) {
        while (getline(logFile, logLine)) { // Read each line from the file
            std::string reformattedLine = reformat(logLine);
            std::cout << reformattedLine << std::endl; // Output the reformatted log line
        }
        logFile.close(); // Close the file when done
    } else {
        std::cerr << "Unable to open log file" << std::endl; // Error message if the file can't be opened
    }

    return 0;
}
