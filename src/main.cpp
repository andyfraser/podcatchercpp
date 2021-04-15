#include <iostream>
#include <memory>
#include "config.hpp"
#include "podcatcher.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    try
    {
        Podcatcher pc(make_unique<Config>(argc > 1 ? argv : NULL));
        pc.run();
    }
    catch(const podcatcher_error& e)
    {
        cerr << e.what() << endl;
    }
    catch(const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
