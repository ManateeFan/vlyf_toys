#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditPassword->setEchoMode(QLineEdit::Password);
    QPixmap pix(":/me.jfif");

//    ui->labelPic->setPixmap(pix.scaled(250,250,Qt::KeepAspectRatio));


    int w = ui->labelPic->width();
    int h = ui->labelPic->height();
    ui->labelPic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEditUsername->text();
    QString password = ui->lineEditPassword->text();

    if("GeniusVlyf" == username && "123" == password)
    {
//        QMessageBox::information(this,"Login","Username and password is ok");
//        hide();
//        secDialog = new SecDialog(this);
//        secDialog->show();

        ui->statusBar->showMessage("Username and password is ok", 5000);
    }
    else
    {
//        QMessageBox::warning(this,"Login","Failed to login");


        ui->statusBar->showMessage("Failed to login", 5000);
    }
}
