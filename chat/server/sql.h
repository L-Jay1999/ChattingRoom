#ifndef SQL_H
#define SQL_H
#include <QSqlDatabase>
#include <QString>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
class SQL
{
public:
    SQL();
    ~SQL();
    bool login(QString user, QString code);
    bool exists(QString user);
    QString getName(QString user);
    bool createUser(QString user, QString code, QString name = "");
    bool deleteUser(QString user);
    bool updateCode(QString user, QString code);
    bool updateName(QString user, QString name);
private:
    const static QString HOST;
    const static int PORT;
    const static QString DB;
    const static QString TABLE;
    const static QString USERNAME;
    const static QString PWD;
    const static QString CREATETABLE;
    const static QString DB_TABLE;
    QSqlDatabase database;
    bool connectDB();
    bool createDB();
};

#endif // SQL_H
