#include "log.hpp"
#include <algorithm>

// Constructor
Log::Log() {}

// Destructor
Log::~Log() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

// Open a log file
bool Log::create_log(const std::string& filename) {
    logFile.open(filename);
    return logFile.is_open();
}

// Move to the next log line
bool Log::next() {
    if (getline(logFile, currentLine)) {
        return true;
    }
    return false;
}

// Return the current line's message
std::string Log::line() {
    size_t startPos = currentLine.find(": ") + 2;
    return startPos != std::string::npos ? currentLine.substr(startPos) : "";
}

// Return the current line's log level
std::string Log::level() {
    size_t start = currentLine.find('[') + 1;
    size_t end = currentLine.find(']');
    if (start != std::string::npos && end != std::string::npos && end > start) {
        std::string logLevel = currentLine.substr(start, end - start);
        std::transform(logLevel.begin(), logLevel.end(), logLevel.begin(), ::toupper);
        return logLevel;
    }
    return "";
}

// Reformat the current log line
std::string Log::reformat() {
    return line() + " (" + level() + ")";
}
