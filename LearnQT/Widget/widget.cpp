#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Genius Vlyf");
    setWindowIcon(QIcon(":/image/me.jfif"));
    QListWidgetItem* item = new QListWidgetItem("Genius Vlyf");
    ui->listWidget->addItem(item);
    item->setTextAlignment(Qt::AlignHCenter);

    ui->listWidget->addItem("vlyf");
    ui->radioButton_2->setChecked(true);
    ui->radioButton_4->setChecked(true);

}

Widget::~Widget()
{
    delete ui;
}
