#ifndef _exceptions
#define _exceptions

#include <exception>
#include <string>

using namespace std;

class podcatcher_error : public exception
{
    private:
        const string message;
    public:
        podcatcher_error(const string msg): message(msg) { }
        const char* what() const throw()
        {
            return message.c_str();
        }
};

#endif