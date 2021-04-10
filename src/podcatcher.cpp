#include <iostream>
#include "podcatcher.hpp"

Podcatcher::Podcatcher()
{
    config = nullptr;
}

Podcatcher::Podcatcher(Config* c)
{
    config = c;
}

void Podcatcher::setConfig(Config* c)
{
    config = c;
}

Config* Podcatcher::getConfig()
{
    return config;
}

void Podcatcher::run()
{
    if(config == nullptr)
    {
        throw podcatcher_error("No config provided");
    }

    cout << "Podcatcher running" << endl;
    cout << "Value = " << config->getFilename() << endl;
}

Podcatcher::~Podcatcher()
{
    if(config != nullptr)
    {
        delete config;
        config = nullptr;
    }

    cout << "Podcatcher stopping" << endl;
}
