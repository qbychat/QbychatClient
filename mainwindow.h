#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "oauth2/oauth2.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Oauth2 *oauth2 = nullptr);
    ~MainWindow();

private slots:
    void on_loginButton_clicked();

private:
    Ui::MainWindow *ui;
    Oauth2 *oauth2;
};
#endif // MAINWINDOW_H
