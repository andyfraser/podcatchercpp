#include <iostream>
#include "podcatcher.hpp"

Podcatcher::Podcatcher(Config* c)
{
    config = c;
}

void Podcatcher::run()
{
    std::cout << "Podcatcher running" << std::endl;
    std::cout << "Value = " << config->getFilename() << std::endl;
}

Podcatcher::~Podcatcher()
{
    delete config;
    std::cout << "Podcatcher stopping" << std::endl;
}
