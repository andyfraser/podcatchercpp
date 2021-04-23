#ifndef _logger
#define _logger

#define MAX_LOG_SIZE 65536
#define LOG_DIR "log"
#define LOG_FILENAME "podcatcher.log"

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
        string directory { LOG_DIR };
        unsigned int maxsize { MAX_LOG_SIZE };
        Logger() : filename(LOG_FILENAME) {};
        Logger(const string fn) : filename(fn) {};
        ~Logger();
        void log(const LogLevel, const string);
};

#endif
