#include <iostream>
#include <memory>
#include <vector>
#include "config.hpp"
#include "podcatcher.hpp"
#include "functions.hpp"

#define RUNFILE ".podcatcher.run"

using namespace std;

int main(int argc, char* argv[])
{
    if(Functions::Filesystem::FileExists(RUNFILE))
    {
        cerr << RUNFILE << " already exists. Exiting." << endl;
        return 1;
    }

    if(!Functions::Filesystem::OpenFile(RUNFILE))
    {
        cerr << RUNFILE << " couldn't be created" << endl;
        return 1;
    }

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

    Functions::Filesystem::DeleteFile(RUNFILE);

    return 0;
}
