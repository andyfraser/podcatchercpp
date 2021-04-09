#include <iostream>
#include "config.hpp"
#include "podcatcher.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        cout << "Not enough arguments" << endl;
        return 1;
    }

    Podcatcher pc(new Config(argv));

    pc.run();

    return 0;
}
