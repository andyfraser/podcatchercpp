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

string Config::getFilename()
{
    return filename;
}

void Config::setFilename(const string fn)
{
    filename = fn;
}
