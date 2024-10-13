#include "networkutil.h"


NetworkUtil::NetworkUtil()
{

}

//获取mac地址
QString NetworkUtil::getMac() {
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();

    foreach (const QNetworkInterface &interface, interfaces) {
        if (interface.flags().testFlag(QNetworkInterface::IsUp) &&
            !interface.flags().testFlag(QNetworkInterface::IsLoopBack)) {
            return interface.hardwareAddress();
        }
    }
    // 如果找不到 MAC 地址，返回一个空字符串
    return QString();
}

//获取联网状态
bool NetworkUtil::checkNetwork(QString url)
{
    QNetworkAccessManager manager;
    QNetworkRequest request(url);
    // 使用HEAD方法发送请求，更快速
    QNetworkReply *reply = manager.head(request);

    QEventLoop eventLoop;
    QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
    // 设置超时时间，防止请求长时间挂起
    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);

    // 超时时间设置为5秒
    timer.setSingleShot(5000);
    timer.start();

     // 进入事件循环等待请求完成
    eventLoop.exec();
    bool isSuccess = reply->error() == QNetworkReply::NoError;
    // 删除网络回应对象
    reply->deleteLater();

    qDebug() << "Link is reachable:" << isSuccess;

    return isSuccess;
}

bool NetworkUtil::isDomainNameValid(const QString &url)
{
    // 创建URL的正则表达式模式
    QRegularExpression regex("^(https?://)?([^/]+)(/.*)?$");

    QRegularExpressionMatch match = regex.match(url);
    if (match.hasMatch()) {
        QString domain = match.captured(2);
        QString path = match.captured(3);

        // 创建域名的正则表达式模式
        QRegularExpression domainRegex("^((?!-)[A-Za-z0-9-]{1,63}(?<!-)\\.)+[A-Za-z]{2,6}$");

        // 使用正则表达式模式进行匹配
        QRegularExpressionMatch domainMatch = domainRegex.match(domain);

        // 验证域名和路径的格式是否符合规范
        bool isDomainValid = domainMatch.hasMatch();
        bool isPathValid = path.isEmpty() || path.startsWith('/');

        // 返回匹配结果
        return isDomainValid && isPathValid;
    }

    return false;
}

//获取服务是否正常
bool NetworkUtil::checkServer(QString url)
{
    HttpUtil* httpUtil=new HttpUtil();
    bool isSuccess=false;
    QString testUrl=url+"/loginbypw";
    QUrlQuery postData;
    postData.addQueryItem("admin", "admin");
    //请求接口
    httpUtil->post(testUrl, postData,
            [&](int status, int code, QString msg, QJsonObject result)
    {
       qDebug()<<"http://bk4.ilabeco.com/api/pc/loginbypw="<<status;
       if(status==200){
           isSuccess=true;
       }

    });
    qDebug()<<"http://bk4.ilabeco.com/api/pc/loginbypw="<<isSuccess;
    return isSuccess;
}
