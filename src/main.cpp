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

    Podcatcher pc(new Config(argv));

    pc.run();

    return 0;
}
