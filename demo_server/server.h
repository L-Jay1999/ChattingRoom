#ifndef SERVER_H
#define SERVER_H
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
using namespace std;


class server
{
public:
    string communication(string msg, string& name, string&roomName, int& kind);
};

#endif // SERVER_H
