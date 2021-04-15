#ifndef _config
#define _config

#define CONFIG_FILENAME "~/.config/podcatcher.conf"

#include <string>

using namespace std;

class Config {
    protected:
        string filename;
        void init(char**);
    
    public:
        Config();
        Config(char**);
        Config(const string);
        ~Config();
        string getFilename();
        void setFilename(const string);
};

#endif
