#include "sql.h"

const QString SQL::HOST = "localhost";
const int SQL::PORT = 3306;
const QString SQL::DB = "chat";
const QString SQL::TABLE_USER = "user";
const QString SQL::TABLE_RECORD = "record";
const QString SQL::TABLE_ROOM = "room";
const QString SQL::USERNAME = "root";
const QString SQL::PWD = "";
//const QString SQL::DB_TABLE = DB + "." + TABLE;
const QString SQL::CREATE_TABLE_USER =
        "create table if not exists " + TABLE_USER +
        "(\
          ID varchar(20) not null primary key,\
          Code varchar(20) not null\
         )default charset = utf8";

const QString SQL::CREATE_TABLE_ROOM =
        "create table if not exists " + TABLE_ROOM +
        "(\
          ID varchar(20) not null primary key,\
          Code varchar(20) not null\
         )default charset = utf8";

const QString SQL::CREATE_TABLE_RECORD =
        "create table if not exists " + TABLE_RECORD +
        "(\
          ID varchar(20) not null,\
          Msg varchar(50),\
          Date datetime\
         )default charset = utf8";


SQL::SQL()
{
    connectDB();
    createDB();
}

SQL::~SQL()
{
    database.close();
}

SQL::SQL(QString md)
{
    setMode(md);
    SQL();
}

void SQL::setMode(QString md)
{
    if(md == "Server")
        MODE = "Server";
    else if(md == "Client")
        MODE = "Client";
    else
        qDebug() << "Error: The mode is incorrect. Default: Server";
}

bool SQL::connectDB()
{
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName(HOST);
    database.setPort(PORT);
    database.setUserName(USERNAME);
    database.setPassword(PWD);
    if(!database.open()){
        qDebug() << database.lastError().text();
        database.close();
        return false;
    }
    return true;
}

bool SQL::createDB()
{
    QString querystring;
    querystring = "create database if not exists " + DB;
    database.exec(querystring);
    if(database.lastError().isValid()){
        qDebug() << database.lastError().text();
        return false;
    }

    database.setDatabaseName(DB);
    if(!database.open()){
        qDebug() << database.lastError().text();
        return false;
    }

    if(MODE == "Server"){
        database.exec(CREATE_TABLE_USER);
        if(database.lastError().isValid()){
            qDebug() << database.lastError().text();
            return false;
        }
    }

    if(MODE == "Server"){
        database.exec(CREATE_TABLE_ROOM);
        if(database.lastError().isValid()){
            qDebug() << database.lastError().text();
            return false;
        }
    }

    if(MODE == "Server"){
        database.exec(CREATE_TABLE_RECORD);
        if(database.lastError().isValid()){
            qDebug() << database.lastError().text();
            return false;
        }
    }

    return true;
}

// bool SQL::createUser(QString user, QString code, QString name)
// {
//     QSqlQuery query;
//     if(!name.size())
//         query.prepare("insert into " + TABLE + " (ID,Code) VALUES (?,?)");
//     else
//         query.prepare("insert into " + TABLE + " (ID,Code,Name) VALUES (?,?,?)");
//     query.addBindValue(user);
//     query.addBindValue(code);
//     if(name.size())
//         query.addBindValue(name);
//     if(query.exec())
//         return true;
//     else{
//         qDebug() << query.lastError().text();
//         return false;
//     }
// }

bool SQL::deleteUser(QString user)
{
    if(MODE == "Server"){
        QSqlQuery query;
        query.prepare("delete from " + TABLE_USER + " where ID = ?");
        query.addBindValue(user);
        if(query.exec())
            return true;
        else{
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return false;
}

bool SQL::updateCode(QString user, QString code)
{
    if(MODE == "Server"){
        QSqlQuery query;
        query.prepare("update " + TABLE_USER + " Code = ? where ID = ?");
        query.addBindValue(code);
        query.addBindValue(user);
        if(query.exec())
            return true;
        else{
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return false;
}

// bool SQL::updateName(QString user, QString name)
// {
//     QSqlQuery query;
//     query.prepare("update " + TABLE + " Name = ? where ID = ?");
//     query.addBindValue(name);
//     query.addBindValue(user);
//     if(query.exec())
//         return true;
//     else{
//         qDebug() << query.lastError().text();
//         return false;
//     }
// }

bool SQL::exists(QString user)
{
    if(MODE == "Server"){
        QSqlQuery query;
        query.prepare("select ID from " + TABLE_USER + " where ID = ?");
        query.addBindValue(user);
        if(query.exec()){
            if(!query.size())
                return false;
            return true;
        }
        else{
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return false;
}

bool SQL::login(QString user, QString code)
{
    if(MODE == "Server"){
        QSqlQuery query;
        query.prepare("select Code from " + TABLE_USER + " where ID = ?");
        query.addBindValue(user);
        if(query.exec()){
            if(!query.size())
                return false;
            query.next();
            if(query.value(0).toString() == code)
                return true;
            else
                return false;
        }
        else{
            qDebug() << query.lastError().text();
            return false;
        }
    }
    return false;
}
