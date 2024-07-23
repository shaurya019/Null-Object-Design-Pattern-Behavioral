#include <iostream>
#include <memory>

// Logger Interface
class Logger {
public:
    virtual ~Logger() = default;
    virtual void log(const std::string& message) const = 0;
};

// ConsoleLogger: A concrete implementation of Logger
class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) const override {
        std::cout << "Log: " << message << std::endl;
    }
};

// NullLogger: A Null Object implementation of Logger
class NullLogger : public Logger {
public:
    void log(const std::string& message) const override {
        // Do nothing
    }
};

// Function that takes a Logger
void process(Logger& logger) {
    logger.log("Processing started.");
    // Some processing
    logger.log("Processing ended.");
}

int main() {
    // Using ConsoleLogger
    ConsoleLogger consoleLogger;
    process(consoleLogger);

    // Using NullLogger
    NullLogger nullLogger;
    process(nullLogger);

    return 0;
}
