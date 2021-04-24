#include "functions.hpp"
#include <iostream>

namespace Functions
{
    bool Filesystem::FileExists(const string& filename)
    {
        ifstream FILE(filename);

        if(FILE)
        {
            return true;
        }

        return false;
    }

    ofstream Filesystem::OpenFile(const string& filename)
    {
        ofstream FILE(filename);

        return FILE;
    }

    int Filesystem::DeleteFile(const string& filename)
    {
        return std::remove(filename.c_str());
    }
}
