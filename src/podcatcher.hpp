#ifndef _podcatcher
#define _podcatcher

#include "config.hpp"

using namespace std;

class Podcatcher
{
    protected:
        Config* config;

    public:
        Podcatcher(Config* config);
        ~Podcatcher();
        void run();
};

#endif
