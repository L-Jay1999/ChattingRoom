#ifndef SQL_H
#define SQL_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QDateTime>
#include <String>

using std::string;

class SQL
{
public:
    SQL();
    ~SQL();
    bool initialize();
    void setMode(string md);
    bool login(QString user, QString code);
    bool exists(QString user);
    //QString getName(QString user);
    bool createUser(QString user, QString code);
    bool exists_room(QString room);
    bool createRoom(QString room, QString code);
    bool enterRoom(QString room, QString code);
    bool deleteUser(QString user);
    bool updateCode(QString user, QString code);
    bool insertMSG(QString user, QString room, QString msg);
    //bool updateName(QString user, QString name);
private:
    const static QString HOST;
    const static int PORT;
    const static QString DB;
    const static QString TABLE_USER;
    const static QString TABLE_RECORD;
    const static QString TABLE_ROOM;
    const static QString USERNAME;
    const static QString PWD;
    const static QString CREATE_TABLE_USER;
    const static QString CREATE_TABLE_ROOM;
    const static QString CREATE_TABLE_RECORD;
    //const static QString DB_TABLE;
    string MODE;
    QSqlDatabase database;
    bool connectDB();
    bool createDB();
};

#endif // SQL_H
