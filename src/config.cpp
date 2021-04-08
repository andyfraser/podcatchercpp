#include <iostream>
#include "config.hpp"

Config::Config()
{
    this->test = 0;
}

Config::Config(char* argv[])
{
    test = atoi(argv[1]);
}

int Config::getTest()
{
    return test;
}

void Config::setTest(int t)
{
    test = t;
}
