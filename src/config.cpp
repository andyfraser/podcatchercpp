#include <iostream>
#include <fstream>
#include "config.hpp"

Config::Config(const vector<string>& args, shared_ptr<Logger> l)
{

    logger = l;

    logger->log(LogLevel::DEBUG, "Passed arguments:");

    for(size_t i = 0; i < args.size(); ++i)
    {
        logger->log(LogLevel::DEBUG, "    " + args[i]);

        if(args[i] == "-l")
        {
            logger->log(LogLevel::DEBUG, "        List only turned on.");
            listonly = true;
        }

        if(args[i] == "-f" && (i + 1) < args.size())
        {
            ++i;
            ifstream file(args[i]);

            if(file)
            {
                logger->log(LogLevel::DEBUG, "        Change filename to " + args[i]);
                filename = args[i];
            }
            else
            {
                --i;
            }
        }
    }
}

Config::~Config()
{
    if(logger)
    {
        logger->log(LogLevel::DEBUG, "Unloading " + filename);
        logger.reset();
    }
}
