#ifndef SERVER_H
#define SERVER_H
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <QTcpSocket>
#include <set>
#include <map>
#include "sql.h"

using std::string;
using std::map;
using std::set;
using std::stringstream;
using std::cout;
using std::endl;

class Server
{
private:
    SQL* sql;
    map<string, string> User;
    map<string, set<string> > Room; // RoomAndItsMembers
public:
    map<string, string> rNP; // RoomNameAndPassword
    map<QTcpSocket*, string> reg; // 防止重复登陆，下线时还需处理
    set<string> online; // 当前上线的用户
public:
    Server();
    ~Server();
    string communication(string msg, string& name, string&roomName, int& kind);
};

#endif // SERVER_H
