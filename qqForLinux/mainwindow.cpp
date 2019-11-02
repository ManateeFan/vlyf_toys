#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("qq For Linux");
    ui->textEditTop->setReadOnly(true);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(push_btn_clicked()));
    connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(clear_btn_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::push_btn_clicked()
{
    ui->textEditTop->append((ui->textEditBottom->toPlainText())+"\n");
    ui->textEditBottom->setText("");
}

void MainWindow::clear_btn_clicked()
{
    ui->textEditTop->setText("");
    ui->textEditBottom->setText("");
}

void MainWindow::action_about_triggered()
{

}
