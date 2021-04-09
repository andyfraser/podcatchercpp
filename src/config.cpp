#include <iostream>
#include "config.hpp"

Config::Config()
{
    filename = "";
}

Config::Config(char* argv[])
{
    filename = argv[1];
}

std::string Config::getFilename()
{
    return filename;
}

void Config::setFilename(std::string fn)
{
    filename = fn;
}
