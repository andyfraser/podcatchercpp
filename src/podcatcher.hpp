#ifndef _podcatcher
#define _podcatcher

#include <memory>
#include "config.hpp"
#include "exceptions.hpp"

using namespace std;

class Podcatcher
{
    protected:
        unique_ptr<Config> config;

    public:
        Podcatcher();
        Podcatcher(unique_ptr<Config> c): config(move(c)) {};
        ~Podcatcher();
        void setConfig(unique_ptr<Config>);
        unique_ptr<Config> getConfig();
        void run();
};

#endif
