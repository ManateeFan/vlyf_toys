#include "splitterdemo.h"
#include "ui_splitterdemo.h"


SplitterDemo::SplitterDemo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SplitterDemo)
{
    ui->setupUi(this);
}

SplitterDemo::~SplitterDemo()
{
    delete ui;
}

void SplitterDemo::on_pushButton_6_clicked()
{
//    SecDialog dialog;
//    dialog.setModal(true);
//    dialog.exec();
    hide();
    dialog = QSharedPointer<SecDialog>(new SecDialog());
    dialog->show();
}
