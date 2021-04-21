#ifndef _logger
#define _logger

#include "exceptions.hpp"

using namespace std;

enum class LogLevel {DEBUG, INFO, WARNING, ERROR, CRITICAL};

class Logger
{
    protected:
        LogLevel level { LogLevel::INFO };
        string filename { "" };
    public:
        Logger();
        Logger(const string);
        ~Logger();
        void setLevel(const LogLevel);
        const LogLevel getLevel();
        const string getLevelAsString();
        void setFilename(const string);
        const string getFilename();
        void log(const LogLevel, const string);
};

#endif