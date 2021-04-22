#ifndef _config
#define _config

#define CONFIG_FILENAME "~/.config/podcatcher.conf"

#include <string>
#include <memory>
#include <vector>
#include "logger.hpp"

using namespace std;

class Config {
    protected:
        shared_ptr<Logger> logger;
        string filename { CONFIG_FILENAME };
    
    public:
        Config(const vector<string>&, shared_ptr<Logger>);
        ~Config();
        string getFilename();
        void setFilename(const string);
};

#endif
