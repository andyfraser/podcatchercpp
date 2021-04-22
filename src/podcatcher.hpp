#ifndef _podcatcher
#define _podcatcher

#include <memory>
#include <vector>
#include "config.hpp"
#include "logger.hpp"
#include "exceptions.hpp"

using namespace std;

class Podcatcher
{
    protected:
        unique_ptr<Config> config;
        shared_ptr<Logger> logger;

    public:
        Podcatcher(const vector<string>&);
        ~Podcatcher();
        void run();
};

#endif
