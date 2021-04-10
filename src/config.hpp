#ifndef _config
#define _config

#include <string>

using namespace std;

class Config {
    protected:
        string filename;
    
    public:
        Config();
        Config(char* argv[]);
        string getFilename();
        void setFilename(const string filename);
};

#endif
