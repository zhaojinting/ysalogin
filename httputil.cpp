
#include "httputil.h"
#include <QJsonDocument>
#include <QMessageBox>
#include <QEventLoop>

//此类封装的是HTTP网络请求
HttpUtil::HttpUtil()
{

}
HttpUtil::~HttpUtil()
{
}


//同步post请求
void HttpUtil::post(QString url, QUrlQuery postData,
    std::function<void(int, int, QString, QJsonObject)> onResponseResult) {
    //http请求
    QNetworkRequest request;//用于设置请求参数，如：请求头、请求URL等
    QNetworkAccessManager nam;//用于发起网络请求，如POST、GET

    connect(&nam, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {//自定义槽函数用于接收网络请求完成后的数据
        //获取Http请求响应状态码
        QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        if (statusCode.isValid()) {
            qDebug() << "Http请求状态码 = " << statusCode.toInt();
        }
        //获取响应源语
        QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        if (reason.isValid()) {
            qDebug() << "Http请求响应源语=" << reason.toString();
        }

        //网络请求错误
        QNetworkReply::NetworkError err = reply->error();
        QByteArray res = reply->readAll();
        QJsonObject doc = QJsonDocument::fromJson(res).object();
        QString message = doc.value("msg").toString();
        int code = doc.value("code").toInt();
        if (err == QNetworkReply::NoError) {//表示网络请求没有错误
            onResponseResult(statusCode.toInt(), code, message, doc);
            qDebug() << "输出网络请求的整体响应结果：" << message;
        }
        else {
            qDebug() << "网络请求发生异常";
            onResponseResult(statusCode.toInt(), -1, reason.toString(), doc);
        }

        //请求完成后释放reply对象
        reply->deleteLater();
        });
    //设置网络请求的URL
    request.setUrl(QUrl(url));
    //请求头token设置
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply* reply = nam.post(request, postData.toString().toUtf8()); //post请求头+传输的数据
    //开启事件循环，直到请求完成
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
}


//异步方式进行请求
void HttpUtil::postAsyn(QString url, QUrlQuery postData,
    std::function<void(int, int, QString, QJsonObject)> onResponseResult) {
    //http请求
    QNetworkRequest request;//用于设置请求参数，如：请求头、请求URL等
    QNetworkAccessManager* nam = new QNetworkAccessManager(this);
    request.setUrl(QUrl(url));

    QNetworkReply* reply = nam->post(request, postData.toString().toUtf8());

        connect(reply, &QNetworkReply::finished, this, [=]() {
            QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
            if (statusCode.isValid()) {
                qDebug() << "HTTP 请求状态码：" << statusCode.toInt();
            }

            QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
            if (reason.isValid()) {
                qDebug() << "HTTP 请求响应源语：" << reason.toString();
            }

            QNetworkReply::NetworkError err = reply->error();
            QByteArray res = reply->readAll();
            QJsonObject doc = QJsonDocument::fromJson(res).object();
            QString message = doc.value("msg").toString();
            int code = doc.value("code").toInt();

            if (err == QNetworkReply::NoError) {
                onResponseResult(statusCode.toInt(), code, message, doc);
                qDebug() << "输出网络请求的整体响应结果：" << doc;
            } else {
                qDebug() << "网络请求发生异常";
                onResponseResult(statusCode.toInt(), -1, reason.toString(), doc);
            }

            reply->deleteLater();
        });
}


void HttpUtil::get(QString url, QMap<QString, QString> parameters, std::function<void(int, QString, QJsonObject)> onResponseResult) {
    //http请求
    QNetworkRequest request;//用于设置请求参数，如：请求头、请求URL等
    QNetworkAccessManager nam;//用于发起网络请求，如POST、GET
    //由于请求发生重定向，所以要加上这行代码，设置自动跳转，否则会返回 302
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    connect(&nam, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {//自定义槽函数用于接收网络请求完成后的数据
        //获取Http请求响应状态码
        QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        if (statusCode.isValid()) {
            qDebug() << "Http请求状态码 = " << statusCode.toInt();
        }
        //获取响应源语
        QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        if (reason.isValid()) {
            qDebug() << "Http请求响应源语=" << reason.toString();
        }

        //网络请求错误
        QNetworkReply::NetworkError err = reply->error();
        QByteArray res = reply->readAll();
        QJsonObject doc = QJsonDocument::fromJson(res).object();
        int code = doc.value("code").toInt();
        QString message = doc.value("msg").toString();
        if (err == QNetworkReply::NoError) {//表示网络请求没有错误
            onResponseResult(code, message, doc);
            //QString
            qDebug() << "输出网络请求的整体响应结果：" << res << endl;
        }
        else {
            qDebug() << "网络请求发生异常";
            onResponseResult( -1, reason.toString(), doc);
        }

        //请求完成后释放reply对象
        reply->deleteLater();
        });

    QUrl requestUrl(url);
    QUrlQuery query;
    //请求头token设置
    //request.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("application/json; charset=UTF-8"));
    for (auto& pair : parameters.toStdMap()) {
        query.addQueryItem(pair.first, pair.second);
    }
    requestUrl.setQuery(query);
    request.setUrl(requestUrl);
    QNetworkReply* reply = nam.get(request);
    qDebug() << "请求方式：Get";
    //开启事件循环，直到请求完成
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
}

//下载网络图片
void HttpUtil::getImage(QString url, std::function<void(int, int, QByteArray)> onResponseResult) {
    //http请求
    QNetworkRequest request;//用于设置请求参数，如：请求头、请求URL等
    QNetworkAccessManager nam;//用于发起网络请求，如POST、GET
    //由于请求发生重定向，所以要加上这行代码，设置自动跳转，否则会返回 302
    request.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    request.setUrl(url);
    connect(&nam, &QNetworkAccessManager::finished, this, [=](QNetworkReply* reply) {//自定义槽函数用于接收网络请求完成后的数据
        //获取Http请求响应状态码
        QVariant statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
        if (statusCode.isValid()) {
            qDebug() << "Http请求状态码 = " << statusCode.toInt();
        }
        //获取响应源语
        QVariant reason = reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toString();
        if (reason.isValid()) {
            qDebug() << "Http请求响应源语=" << reason.toString();
        }

        //网络请求错误
        QNetworkReply::NetworkError err = reply->error();
        QByteArray res = reply->readAll();
        if (err == QNetworkReply::NoError) {//表示网络请求没有错误
            onResponseResult(statusCode.toInt(), 1,res);
        }
        else {
            qDebug() << "网络请求发生异常";
            onResponseResult(statusCode.toInt(), -1,res);
        }

        //请求完成后释放reply对象
        reply->deleteLater();
        });
    //设置网络请求的URL
    request.setUrl(QUrl(url));

    //请求头token设置
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    QNetworkReply* reply = nam.get(request); //post请求头+传输的数据
    qDebug() << "请求方式：Get";
    //开启事件循环，直到请求完成
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    loop.exec();
}


