#ifndef CONST_H
#define CONST_H
#include <QString>
#include <QTcpSocket>
#include <string>
using std::string;

extern const QString button1_pic;
extern const QString button2_pic;
extern const QString button3_pic;
extern const QString button4_pic;
extern const QString main_pic;
extern const QString chat_pic;

extern QTcpSocket *tcpClient;
extern string _name;
extern string _input_name;
extern string _roomName;
extern string _input_roomName;
extern QString roominfo;
extern QString clientinfo;
#endif // CONST_H
