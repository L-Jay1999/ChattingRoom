#include "server.h"

Server::Server()
{
    sql = new SQL();
    sql->setMode("Server");
    sql->initialize();
}

Server::~Server()
{
    delete sql;
}

string Server::communication(string input, string& name, string& roomName, int& kind)
{
    string password, roomPassword;
    if(input[0] == 'S'){
        if(input[1] == 'D') // 登(Deng)录
        {
            kind = 1;        // kind=1，返回mainwindow.cpp后不需要任何处理
            string temp = input.substr(2);
            stringstream s(temp);
            s >> name >> password;
//            if(User.count(name) && User[name] == password)
//            {
//                return "YL";
//            }
            QString qtemp1 = QString::fromStdString(name);
            QString qtemp2 = QString::fromStdString(password);
            if(sql->exists(qtemp1)&&sql->login(qtemp1,qtemp2)){
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
//            if(!User.count(name))
//            {
//                User[name] = password;
//                return "YL";
//            }
            QString qtemp1 = QString::fromStdString(name);
            QString qtemp2 = QString::fromStdString(password);
            if(!sql->exists(qtemp1)){
                sql->createUser(qtemp1, qtemp2);
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
            s >> roomName >> roomPassword;
            QString qtemp1 = QString::fromStdString(roomName);
            QString qtemp2 = QString::fromStdString(roomPassword);
//            if(!rNP.count(roomName))  // 此房间原来不存在，可以创建
//            {
//                rNP[roomName] = roomPassword;
//                Room[roomName].insert(name);
//                return "YD";
//            }
            if(!sql->exists_room(qtemp1)){
                sql->createRoom(qtemp1, qtemp2);
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
            QString qtemp1 = QString::fromStdString(roomName);
            QString qtemp2 = QString::fromStdString(roomPassword);
//            if(rNP.count(roomName) && rNP[roomName] == roomPassword)
//            {
//                Room[roomName].insert(name);
//                return "YD";
//            }
            if(sql->exists_room(qtemp1) && sql->enterRoom(qtemp1, qtemp2)){
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
        QString qtemp1 = QString::fromStdString(name);
        QString qtemp2 = QString::fromStdString(roomName);
        QString qtemp3 = QString::fromStdString(input);
        sql->insertMSG(qtemp1, qtemp2, qtemp3);
        return ret;
    }
}
