#include <iostream>
#include "podcatcher.hpp"

Podcatcher::Podcatcher(Config* c)
{
    config = c;
}

void Podcatcher::run()
{
    cout << "Podcatcher running" << endl;
    cout << "Value = " << config->getFilename() << endl;
}

Podcatcher::~Podcatcher()
{
    delete config;
    cout << "Podcatcher stopping" << endl;
}
