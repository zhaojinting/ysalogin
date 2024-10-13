#include "settings.h"

QString Settings::g_url = "";
QString Settings::g_ip = "";
QString Settings::g_server = "";
QString Settings::g_mac = "";
QString Settings::g_instrumentId = "";
QString Settings::g_orderId = "";
QString Settings::g_token="";
QMainWindow* Settings::m_mainWindow=0;
QString Settings::g_isadmin="";
QString Settings::g_type;
QString Settings::g_tempOrderId="";


Settings::Settings()
{

}

Settings::~Settings()
{

}

void Settings::initConfig()
{
    setUrl(Database::getDatabase()->getConfig("url"));
    setIp(Database::getDatabase()->getConfig("ip"));
    setMac(Database::getDatabase()->getConfig("mac"));
    setServer(Database::getDatabase()->getConfig("server"));
    setInstrumentId(Database::getDatabase()->getConfig("instrumentId"));
    setToken(Database::getDatabase()->getConfig("token"));
    setOrderId(Database::getDatabase()->getConfig("orderId"));
    setIsAdmin(Database::getDatabase()->getConfig("isAdmin"));
    setType(Database::getDatabase()->getConfig("type"));
    setTempOrderId(Database::getDatabase()->getConfig("tempOrderId"));
}

void Settings::setUrl(const QString& url) {
    g_url = url;
}

QString Settings::getUrl() {
    return g_url;
}

void Settings::setToken(const QString& token) {
    g_token = token;
}

QString Settings::getToken() {
    return g_token;
}

void Settings::setIp(const QString& ip) {
    g_ip = ip;
}

QString Settings::getIp() {
    return g_ip;
}

void Settings::setServer(const QString& server) {
    g_server = server;
}

QString Settings::getServers() {
    if(g_server=="url") {
        return g_url;
    } else {
        return g_ip;
    }
}

QString Settings::getServer() {
    return g_server;
}

void Settings::setMac(const QString& mac) {
    g_mac = mac;
}

QString Settings::getMac() {
    return g_mac;
}

void Settings::setInstrumentId(const QString& id) {
    g_instrumentId = id;
}

QString Settings::getInstrumentId() {
    return g_instrumentId;
}

void Settings::setOrderId(const QString& id) {
    g_orderId = id;
}

QString Settings::getOrderId() {
    return g_orderId;
}

void Settings::setMainWindow( QMainWindow* mainWindow) {
    m_mainWindow = mainWindow;
}

QMainWindow* Settings::getMainWindow() {
    return m_mainWindow;
}

void Settings::setIsAdmin(const QString& isAdmin) {
    g_isadmin = isAdmin;
}

QString Settings::getIsAdmin() {
    return g_isadmin;
}

void Settings::setType(const QString& id) {
    g_type = id;
}

QString Settings::getType() {
    return g_type;
}

void Settings::setTempOrderId(const QString& id) {
    g_tempOrderId = id;
}

QString Settings::getTempOrderId() {
    return g_tempOrderId;
}



