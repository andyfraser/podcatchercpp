#ifndef _GENERAL
#define _GENERAL

#include <string>
#include <fstream>

using namespace std;

namespace Functions
{
    class Filesystem
    {
        public:
            static bool FileExists(const string&);
            static ofstream OpenFile(const string&);
            static int DeleteFile(const string&);
    };
}

#endif
