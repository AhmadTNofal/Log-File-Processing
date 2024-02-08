#pragma once
#include <string>
#include <fstream>

class Log {
private:
    std::ifstream logFile;
    std::string currentLine;

public:
    Log();
    ~Log();
    bool create_log(const std::string& filename);
    bool next();
    std::string line();
    std::string level();
    std::string reformat();
};
