#include <iostream>
#include <memory>
#include "podcatcher.hpp"

Podcatcher::Podcatcher(const vector<string>& args)
{
    logger = make_shared<Logger>();
    config = make_unique<Config>(args, logger);
}

void Podcatcher::setConfig(unique_ptr<Config> c)
{
    config = move(c);
}

unique_ptr<Config> Podcatcher::getConfig()
{
    return move(config);
}

void Podcatcher::run()
{
    if(!config)
    {
        throw podcatcher_error("Podcatcher: No config provided");
    }

    logger->log(LogLevel::INFO, "Podcatcher running");
    logger->log(LogLevel::DEBUG, "Value = " + config->getFilename());
}

Podcatcher::~Podcatcher()
{
    logger->log(LogLevel::INFO, "Podcatcher stopping");

    if(config)
    {
        config.reset(nullptr);
    }

    if(logger)
    {
        logger.reset();
    }
}
