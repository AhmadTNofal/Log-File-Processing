#include "log.hpp"
#include "simpletest.h"

using namespace std;

char const * groups[] = {
    "Log",
};

// Test 1: Successfully opening a log file
DEFINE_TEST_G(LogOpenTest, Log) {
    Log log;
    bool success = log.create_log("log.in");
    TEST_MESSAGE(success == true, "Failed to open log file!");
}

// Test 2: Fail to open a non-existent log file
DEFINE_TEST_G(LogOpenFailTest, Log) {
    Log log;
    bool success = log.create_log("nonexistent_log.in");
    TEST_MESSAGE(success == false, "Should fail to open a non-existent log file!");
}

// Test 3: Successfully read a line from the log file
DEFINE_TEST_G(LogReadTest, Log) {
    Log log;
    log.create_log("log.in");
    bool success = log.next();
    TEST_MESSAGE(success == true, "Failed to read a line from the log file!");
}

// Test 4: Reach the end of the log file
DEFINE_TEST_G(LogEOFTest, Log) {
    Log log;
    log.create_log("log.in");
    while (log.next()); // Read until the end
    TEST_MESSAGE(!log.next(), "Did not reach the end of the log file as expected!");
}

// Test 5: Verify the content of the log line
DEFINE_TEST_G(LogContentTest, Log) {
    Log log;
    log.create_log("log.in");
    log.next(); // Assuming the first line is what we want to test
    string line = log.line();
    TEST_MESSAGE(line == "Expected log line content", "Log line content did not match expected!");
}

int main() {
    bool pass = true;
    for (auto group : groups) {
        pass &= TestFixture::ExecuteTestGroup(group, TestFixture::Verbose);
    }
    return pass ? 0 : 1;
}
