#ifndef _logger
#define _logger

#include "exceptions.hpp"

using namespace std;

enum class LogLevel {DEBUG, INFO, WARNING, ERROR, CRITICAL};

class Logger
{
    public:
    #ifdef DEBUG_SETTINGS
        LogLevel level { LogLevel::DEBUG };
    #else
        LogLevel level { LogLevel::INFO };
    #endif
        string filename;
        Logger() : filename("") {};
        Logger(const string fn) : filename(fn) {};
        ~Logger();
        void log(const LogLevel, const string);
};

#endif