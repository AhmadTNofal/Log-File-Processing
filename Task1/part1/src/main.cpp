#include <iostream>
#include <fstream>
#include <string>

// Function to extract the message from a log line
std::string extractMessage(const std::string& logLine) {
    size_t startPos = logLine.find(": ") + 2; // Find the start of the message just after ": "
    if (startPos != std::string::npos) {
        return logLine.substr(startPos); // Extract the message part
    }
    return ""; // Return an empty string if the format is incorrect
}

int main() {
    std::ifstream logFile("log.in"); // Open the log file
    std::string logLine;

    if (logFile.is_open()) {
        while (getline(logFile, logLine)) { // Read each line from the file
            std::string message = extractMessage(logLine);
            std::cout << message << std::endl; // Output the extracted message
        }
        logFile.close(); // Close the file when done
    } else {
        std::cerr << "Unable to open log file" << std::endl; // Error message if the file can't be opened
    }

    return 0;
}
