#include <iostream>
#include <memory>
#include "podcatcher.hpp"

Podcatcher::Podcatcher()
{
    config = nullptr;
}

void Podcatcher::setConfig(unique_ptr<Config> c)
{
    config.reset(nullptr);
    config = move(c);
}

unique_ptr<Config> Podcatcher::getConfig()
{
    return move(config);
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
        config.reset(nullptr);
    }

    cout << "Podcatcher stopping" << endl;
}
