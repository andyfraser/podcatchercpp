#include <iostream>
#include "config.hpp"
#include "podcatcher.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        cout << "Usgae: podcatcher FILENAME" << endl;
        return 1;
    }

    try
    {
        Podcatcher pc(new Config(argv));
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
