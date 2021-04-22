#include <iostream>
#include "logger.hpp"

Logger::Logger()
{
}

Logger::Logger(const string fn)
{
    filename = fn;
}

Logger::~Logger()
{
    log(LogLevel::DEBUG, "Unloading logger");
}

void Logger::setLevel(const LogLevel ll)
{
    level = ll;
}

const LogLevel Logger::getLevel()
{
    return level;
}

const string Logger::getLevelAsString()
{
    string msg { "" };
    switch(level)
    {
        case LogLevel::DEBUG:
            msg = "Debug";
            break;
        case LogLevel::INFO:
            msg = "Info";
            break;
        case LogLevel::WARNING:
            msg = "Warning";
            break;
        case LogLevel::ERROR:
            msg = "Error";
            break;
        case LogLevel::CRITICAL:
            msg = "Critical";
            break;
        default:
            msg = "No Level";
            break;
    }

    return msg;
}

void Logger::setFilename(const string fn)
{
    filename = fn;
}

const string Logger::getFilename()
{
    return filename;
}

void Logger::log(const LogLevel ll, const string msg)
{
    if(ll >= level)
    {
        if(ll >= LogLevel::ERROR)
        {
            cerr << msg << endl;
        }
        else
        {
            cout << msg << endl;
        }
    }
}
