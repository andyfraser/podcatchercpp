#ifndef _config
#define _config

class Config {
    protected:
        int test;
    
    public:
        Config();
        Config(char* argv[]);
        int getTest();
        void setTest(int t);
};

#endif
