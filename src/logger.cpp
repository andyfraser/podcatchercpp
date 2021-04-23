#include <iostream>
#include "logger.hpp"

Logger::~Logger()
{
    log(LogLevel::DEBUG, "Unloading logger");
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
