#ifndef _logger
#define _logger

#include "exceptions.hpp"

using namespace std;

enum class LogLevel {DEBUG, INFO, WARNING, ERROR, CRITICAL};

class Logger
{
    protected:
        LogLevel level;
    public:
        Logger();
        ~Logger();
        void setLevel(LogLevel);
        void log(LogLevel, string);
};

#endif