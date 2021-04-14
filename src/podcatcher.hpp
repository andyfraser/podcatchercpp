#ifndef _podcatcher
#define _podcatcher

#include "config.hpp"
#include "exceptions.hpp"

using namespace std;

class Podcatcher
{
    protected:
        Config* config;

    public:
        Podcatcher();
        Podcatcher(Config*);
        ~Podcatcher();
        void setConfig(Config*);
        Config* getConfig();
        void run();
};

#endif
