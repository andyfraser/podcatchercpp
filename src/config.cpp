#include <iostream>
#include "config.hpp"

Config::Config(const vector<string>& args, shared_ptr<Logger> l)
{
    logger = l;

    logger->log(LogLevel::DEBUG, "Passed arguments:");
    for(string s: args)
    {
        logger->log(LogLevel::DEBUG, "\t" + s);
    }
}

string Config::getFilename()
{
    return filename;
}

void Config::setFilename(const string fn)
{
    filename = fn;
}

Config::~Config()
{
    if(logger)
    {
        logger->log(LogLevel::DEBUG, "Unloading " + filename);
        logger.reset();
    }
}
