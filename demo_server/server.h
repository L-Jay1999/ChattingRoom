#ifndef SERVER_H
#define SERVER_H
#include <string>
using namespace std;


class server
{
public:
    string communication(string msg, string& name, string&roomName, int& kind);
};

#endif // SERVER_H
