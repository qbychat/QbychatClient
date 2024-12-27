#include "oauth2.h"
#include <QTextStream>
#include <QDebug>

Oauth2::Oauth2(QString url) : QObject() {
    this->auth_url = url;
}

Oauth2::~Oauth2() {

}

QString Oauth2::get_client_id() {
    QFile file("clientid.txt");
    if (file.exists() && file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString client_id = in.readLine();
        file.close();
        return client_id;
    } else {
        QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
        for (const QNetworkInterface &interface : interfaces) {
            if (interface.flags().testFlag(QNetworkInterface::IsUp) &&
                !interface.flags().testFlag(QNetworkInterface::IsLoopBack)) {
                return interface.hardwareAddress().remove(':');
            }
        }
    }
    return QString();
}

void Oauth2::login() {
    this->oauth2_flow.setAccessTokenUrl(this->auth_url + "/oauth2/token");
    this->oauth2_flow.setAuthorizationUrl(this->auth_url + "/oauth2/authorize");
    this->oauth2_flow.setClientIdentifier(get_client_id());

    connect(&this->oauth2_flow, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, this, [](const QUrl &url) {
        QDesktopServices::openUrl(url);
    });
    connect(&this->oauth2_flow, &QOAuth2AuthorizationCodeFlow::granted, this, [this]() {
        qDebug() << "Granted! token:" << this->oauth2_flow.token();
    });
    this->oauth2_flow.grant();
}