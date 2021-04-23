#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include "config.hpp"
#include "podcatcher.hpp"

#define RUNFILE ".podcatcher.run"

using namespace std;

int main(int argc, char* argv[])
{
    ifstream checkrunfile(RUNFILE);

    if(checkrunfile)
    {
        cerr << RUNFILE << " already exists. Exiting." << endl;
        return 1;
    }

    ofstream runfile(RUNFILE);

    if(!runfile)
    {
        cerr << RUNFILE << " couldn't be created" << endl;
        return 1;
    }

    runfile.close();

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

    remove(RUNFILE);

    return 0;
}
