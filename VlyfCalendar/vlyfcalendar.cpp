#include "vlyfcalendar.h"
#include "ui_vlyfcalendar.h"
#include <QMessageBox>
#include <QLabel>

VlyfCalendar::VlyfCalendar(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VlyfCalendar)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/image/me.jfif"));
    ui->statusBar->addPermanentWidget(new QLabel("Vlyf:Welcome"));
    connect(ui->actionAbout,&QAction::triggered,this,&VlyfCalendar::AboutActionTriggered);
}

VlyfCalendar::~VlyfCalendar()
{
    delete ui;
}

void VlyfCalendar::AboutActionTriggered()
{
    QMessageBox::about(this,"关于","Welcome to use Vlyf Calendar.\n"
                                 "                         Designed by vlyf\n"
                                 "                             2019.11.3");
}
