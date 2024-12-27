#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qpushbutton.h>

MainWindow::MainWindow(QWidget *parent, Oauth2 *oauth2)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->oauth2 = oauth2;
    connect(ui->LoginButton, &QPushButton::clicked, this, &MainWindow::on_loginButton_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loginButton_clicked()
{
    this->oauth2->login();
}