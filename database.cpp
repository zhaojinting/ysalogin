#include "database.h"

QString dbname="app.conf";
QString password="Ysa@2024";

//配置表
QString configTable="config";
//用户表
QString userTable="user";

Database *Database::g_database = 0;


/**
 *  基于加密sqlite的配置文件
 */
Database::Database()
{

}

Database::~Database()
{
    releaseConf();
}

bool Database::isDbExistAndCreated() {
    return installAndInit(QCoreApplication::applicationDirPath() + dbname, password, false);
}

bool Database::setConfig(QString key,QString value) {
    return addConfigItem(configTable, key, value);
}

QString Database::getConfig(QString key) {
    QString tempValue;
    getConfigItem(configTable, key, tempValue);
    return tempValue;
}

bool Database::setUser(QString key,QString value) {
    return addConfigItem(userTable, key, value);
}

QString Database::getUser(QString key) {
    QString tempValue="";
    getConfigItem(userTable, key, tempValue);
    return tempValue;
}

void Database::setDatabase(Database* database) {
    g_database = database;
}

Database* Database::getDatabase() {
    return g_database;
}
