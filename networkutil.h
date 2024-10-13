#ifndef NETWORKUTIL_H
#define NETWORKUTIL_H

#include <QAtomicInt>
#include <QNetworkInterface>
#include <QNetworkConfigurationManager>
#include <QNetworkConfiguration>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QTimer>
#include "httputil.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>

class NetworkUtil
{
public:
    NetworkUtil();
    static QString getMac();
    static bool checkNetwork(QString url);
    static bool isDomainNameValid(const QString &domain);
    static bool checkServer(QString url);

};

#endif // NETWORKUTIL_H
