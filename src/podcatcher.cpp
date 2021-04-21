#include <iostream>
#include <memory>
#include "podcatcher.hpp"

Podcatcher::Podcatcher()
{
    config = nullptr;
    init();
}

Podcatcher::Podcatcher(unique_ptr<Config> c)
{
    config = move(c);
    init();
}

void Podcatcher::init()
{
    logger = make_unique<Logger>();
    logger->log(LogLevel::DEBUG, "Logger filename = '" + logger->getFilename() + "'");
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
        logger->log(LogLevel::DEBUG, "Unloading config file " + config->getFilename());
        config.reset(nullptr);
    }

    if(logger)
    {
        logger->log(LogLevel::DEBUG, "Unloading logger");
        logger.reset(nullptr);
    }
}
