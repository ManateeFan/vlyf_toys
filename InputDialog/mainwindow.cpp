#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("InputDialog练习");
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(GetText()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::GetText()
{
    bool ok;
    QString text=QInputDialog::getText(this,"GetText","Input your text",QLineEdit::Normal,"Your text",&ok);
    if(ok)
    {
        QMessageBox::information(this, "Information", "Your comment is: <b>" + text + "</b>", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    }
}
