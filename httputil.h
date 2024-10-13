#ifndef HTTPUTIL_H
#define HTTPUTIL_H
#include <functional>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QUrlQuery>
#include <QJsonObject>
#include <QString>
#include <QMap>
#include <QObject>
#include <QMessageBox>
#include <QJsonArray>

class HttpUtil : public QObject
{
    Q_OBJECT
public:
    HttpUtil();
        ~HttpUtil();


public:
    void post(QString url,QUrlQuery postData, std::function<void(int, int, QString, QJsonObject)> onResponseResult);

    void postAsyn(QString url,QUrlQuery postData,std::function<void(int, int, QString, QJsonObject)> onResponseResult);

    void get(QString url,  QMap<QString, QString> headers, std::function<void(int, QString, QJsonObject)> onResponseResult);

    void getImage(QString url, std::function<void(int, int, QByteArray)> onResponseResult);






};

#endif // HTTPUTIL_H

