#include "server.h"
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <set>
#include <map>
using namespace std;

map<string, string> User;
//set<string> reg; // 防止重复登陆，下线时还需处理
map<string, set<string> > Room; // RoomAndItsMembers
map<string, string> rNP; // RoomNameAndPassword

string server::communication(string input, string& name, string& roomName, int& kind)
{
    string password, roomPassword;
    if(input[0] == 'S'){
        if(input[1] == 'D') // 登(Deng)录
        {
            kind = 1;        // kind=1，返回mainwindow.cpp后不需要任何处理
            string temp = input.substr(2);
            stringstream s(temp);
            s >> name >> password;
            if(User.count(name) && User[name] == password)
            {
                return "YL";
            }
            else
            {
                return "N";
            }
        }
        if(input[1] == 'Z') // 注(Zhu)册
        {
            kind = 1;
            string temp = input.substr(2);
            stringstream s(temp);
            s >> name >> password;
            if(!User.count(name))
            {
                User[name] = password;
                return "YL";
            }
            else
            {
                return "N";
            }
        }
        if(input[1] == 'C') //  请求创建(Create)某聊天室
        {
            // kind=3 && return="Y"，返回mainwindow.cpp后需要把name用户的*socket加入到roomName的集合中
            kind = 3;
            string temp = input.substr(2);
            stringstream s(temp);
            s >> name >> roomName >> roomPassword;
            if(!rNP.count(roomName))  // 此房间原来不存在，可以创建
            {
                rNP[roomName] = roomPassword;
                Room[roomName].insert(name);
                return "YD";
            }
            else
                return "N";


        }
        if(input[1] == 'E') // 请求进入(Enter)某聊天室
        {
            kind = 3;
            string temp = input.substr(2);
            stringstream s(temp);
            s >> name >> roomName >> roomPassword;
            if(rNP.count(roomName) && rNP[roomName] == roomPassword)
            {
                Room[roomName].insert(name);
                return "YD";
            }
            else
                return "N";
        }


    }
    if(input[0] == 'M'){
        // kind=2，向roomName集合内的所有*socket发送形式为[name]:input的消息
        kind = 2;
        string temp = input.substr(1);
        stringstream s(temp);
        s >> name >> roomName >> input;
        string ret = "[" + name + "] : " + input;
        return ret;
    }
}
