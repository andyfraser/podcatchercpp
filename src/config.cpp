#include <iostream>
#include "config.hpp"

Config::Config()
{
    init(NULL);
}

Config::Config(char* argv[])
{
    init(argv);
}

Config::Config(const string fn)
{
    filename = fn;
}

void Config::init(char* argv[])
{
    if(argv)
    {
        filename = argv[1];
    }
    else
    {
        filename = CONFIG_FILENAME;
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
    cout << "Unloading " << filename << endl;
}
