#ifndef _config
#define _config

#include <string>

class Config {
    protected:
        std::string filename;
    
    public:
        Config();
        Config(char* argv[]);
        std::string getFilename();
        void setFilename(std::string filename);
};

#endif
