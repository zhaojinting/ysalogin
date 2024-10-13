#ifndef DATDBASE_H
#define DATDBASE_H

#include <QCoreApplication>

#include "nconfig.h"

class Database: public NConfig
{
public:
    Database();
    ~Database();

    /**
     * 数据库是否存在，不存在则自动创建
    */
    bool isDbExistAndCreated();
    /**
     * 设置配置文件
    */
    bool setConfig(QString key,QString value);
    /**
     * 获取配置文件
    */
    QString getConfig(QString key);
        /**
     * 设置用户
    */
    bool setUser(QString key,QString value);
    /**
     * 获取用户
    */
    QString getUser(QString key);
    /**
     * 设置公共变量
     */
    static void setDatabase(Database* Database);
    /**
     * 获取公共变量
     */
    static Database* getDatabase();
private:
       static Database *g_database;
};

#endif // DATDBASE_H
