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
        Podcatcher(Config* c);
        ~Podcatcher();
        void setConfig(Config* c);
        Config* getConfig();
        void run();
};

#endif
