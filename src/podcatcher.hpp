#ifndef _podcatcher
#define _podcatcher

#include <memory>
#include "config.hpp"
#include "logger.hpp"
#include "exceptions.hpp"

using namespace std;

class Podcatcher
{
    protected:
        unique_ptr<Config> config;
        unique_ptr<Logger> logger;
        void init();

    public:
        Podcatcher();
        Podcatcher(unique_ptr<Config>);
        ~Podcatcher();
        void setConfig(unique_ptr<Config>);
        unique_ptr<Config> getConfig();
        void run();
};

#endif
