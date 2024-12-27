#include "mainwindow.h"
#include "oauth2/oauth2.h"

#include <QApplication>

Oauth2 *oauth2;

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    qDebug()<<"Oauth2 front";

    oauth2 = new Oauth2("https://localhost:9000/");

    qDebug()<<"Oauth2 behind";

    MainWindow w(nullptr, oauth2);

    qDebug()<<"mainwindow";

    w.show();

    qDebug()<<"show";

    return a.exec();
}