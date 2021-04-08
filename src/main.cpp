#include <iostream>
#include "config.hpp"
#include "podcatcher.hpp"

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        std::cout << "Not enough arguments" << std::endl;
        return 1;
    }

    Podcatcher* pc = new Podcatcher(new Config(argv));

    pc->run();

    delete pc;

    return 0;
}
