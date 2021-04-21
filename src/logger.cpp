#include <iostream>
#include "logger.hpp"

Logger::Logger()
{
    level = LogLevel::INFO;
}

Logger::~Logger()
{
}

void Logger::setLevel(LogLevel ll)
{
    level = ll;
}

void Logger::log(LogLevel ll, string msg)
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
