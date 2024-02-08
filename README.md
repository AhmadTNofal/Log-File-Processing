# Internet of Things (IoT)

This project is designed to introduce fundamental concepts of IoT systems, focusing on log file processing and testing methodologies. It is structured into three main tasks, each building upon the previous to enhance the project's functionality and robustness.

## Getting Started

These instructions will help you get a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

- C++17 compatible compiler (e.g., `g++` or `clang++`)
- Make (for building the project)
- SimpleTest framework (included as a submodule)

### Installing

1. Clone the repository and navigate into the project directory:
    ~~~bash
    git clone https://gitlab.uwe.ac.uk/a5-hasan/iot_starter.git
    cd iot_starter
    ~~~

2. Initialize and update the SimpleTest submodule:
    ~~~bash
    git submodule init
    git submodule update
    ~~~

3. Build the project using `make`:
    ~~~bash
    make
    ~~~

## Task 1: Basic Log Processing

The first task introduces a simple C++ application that processes log files. The application reads log entries from a file and displays their content.

### Features

- Reading log entries from a file.
- Displaying log content to the console.

### Usage

Run the application with:

#### Make
~~~bash
make
~~~

#### Build
~~~ bash
./build/app
~~~

# Task 2: Advanced Log Processing and Testing
Building on Task 1, this task enhances the log processing application with advanced features, by introducing log functionalities.

## Features
- **Advanced Log Processing:** Implements sophisticated log file parsing and data extraction techniques to handle complex log formats.

## Files
- <code style="color : lightGreen">log.hpp</code>
- <code style="color : lightGreen">log.cpp</code>
- <code style="color : lightGreen">main.cpp</code>

## Usage

#### Make
~~~bash
make
~~~

#### Build
~~~ bash
./build/app
~~~


# Task 3: Comprehensive Testing and Error Handling
This task extends the testing framework established in Task 2 and improves the application's robustness by implementing comprehensive error handling mechanisms.

## Features
- Comprehensive Testing: Expands the test suite to cover edge cases and less common scenarios, ensuring the application can handle a wide range of inputs and situations.
- Error Handling: Enhances the application's resilience by implementing robust error handling strategies, preventing crashes and undefined behavior in the face of unexpected conditions.
## Running Tests
Execute the following command to compile and run the unit tests:

~~~bash
make test
~~~
This command builds the test suite and executes tests, reporting any failures and ensuring that all components behave as expected.


## Running Enhanced Tests
To run the comprehensive test suite, use the command:

~~~bash
./build/log_tests
~~~
This will execute an extended series of tests, providing detailed output on each test's status and highlighting any areas that require attention.

# Additional Instructions:
- Ensure that all prerequisites are met before running the tests, including any required setup or configuration.
- Review the test output carefully to identify and resolve any issues that may arise, ensuring the log processing application is reliable and robust under various conditions.