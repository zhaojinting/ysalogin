#ifndef SETTINGS_H
#define SETTINGS_H
#include <QMainWindow>
#include "database.h"
class MainWindow;   // 前置声明
class Settings
{
public:
    Settings();
    ~Settings();
    /**
     * 初始参数
     */
    void initConfig();
private:
    static QString g_url;
    static QString g_ip;
    static QString g_server;
    static QString g_mac;
    static QString g_instrumentId;
    static QString g_orderId;
    static QString g_token;
    static QMainWindow *m_mainWindow;
    static QString g_isadmin;
    static QString g_type;
    static QString g_tempOrderId;

public:
    static void setUrl(const QString& url);
    static QString getUrl();

    static void setToken(const QString& token);
    static QString getToken();
    static void setIp(const QString& ip);
    static QString getIp();
    static void setServer(const QString& server);
    static QString getServers();
    static QString getServer();
    static void setMac(const QString& mac);
    static QString getMac();
    static void setInstrumentId(const QString& id);
    static QString getInstrumentId();
    static void setOrderId(const QString& id);
    static QString getOrderId();
    static void setMainWindow(QMainWindow* mainWindow);
    static QMainWindow* getMainWindow();
    static void setIsAdmin(const QString& isAdmin);
    static QString getIsAdmin();
    static void setType(const QString& id);
    static QString getType();
    static void setTempOrderId(const QString& id);
    static QString getTempOrderId();


};

#endif // SETTINGS_H
