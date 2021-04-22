#include <iostream>
#include <memory>
#include <vector>
#include "config.hpp"
#include "podcatcher.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    vector<string> args(argv + 1, argv + argc);

    try
    {
        Podcatcher pc(args);
        pc.run();
    }
    catch(const podcatcher_error& e)
    {
        cerr << e.what() << endl;
    }
    catch(const logger_error& e)
    {
        cerr << "Logger error: " << e.what() << endl;
    }
    catch(const exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
