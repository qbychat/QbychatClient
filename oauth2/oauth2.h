#ifndef OAUTH2_H
#define OAUTH2_H

#include <QOAuth2AuthorizationCodeFlow>
#include <QNetworkInterface>
#include <QCryptographicHash>
#include <QString>
#include <QFile>
#include <QDesktopServices>

class Oauth2 : public QObject // Fixed inheritance issue by adding 'public'
{
    Q_OBJECT // Added Q_OBJECT macro for QObject derived class

public:
    Oauth2(QString url);
    ~Oauth2();
    void login();
    QString get_client_id();

private:
    QOAuth2AuthorizationCodeFlow oauth2_flow;
    QString auth_url;
};

#endif // OAUTH2_H