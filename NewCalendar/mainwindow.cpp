#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSpinBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    selectDate = QDate::currentDate();
    fontSize = 10;
    QWidget *centralWidget = new QWidget;
    //top
    QLabel *dateLabel = new QLabel(tr("Date:"));
    QComboBox *monthCombo = new QComboBox();//月份下拉列表
    for(int month=1; month <=12; month++)
    {
        monthCombo->addItem(QDate::longMonthName(month));
    }
    //填写年份
    QDateTimeEdit *yearEdit = new QDateTimeEdit;//可编辑的显示时间的控件
    yearEdit->setDisplayFormat("yyyy");

    yearEdit->setDateRange(QDate(1970,1,1),QDate(9999,1,1));

    monthCombo->setCurrentIndex(selectDate.month()-1);//默认显示的月
    yearEdit->setDate(selectDate);//默认显示的年份
    //填写字体大小
    QLabel *fontSizeLabel = new QLabel(tr("size:"));
    QSpinBox *sizeSpinBox = new QSpinBox;
    sizeSpinBox->setValue(14);  //默认字体大小
    sizeSpinBox->setRange(1,64);//字体设置范围
    //插入Calendar
    insertCalendar();

    connect(monthCombo,SIGNAL(activated(int)),this,SLOT(setMonth(int)));
    connect(yearEdit,SIGNAL(dataChanged(QDate)),this,SLOT(setYear(QDate)));
    connect(sizeSpinBox,SIGNAL(valueChanged(int)),this,SLOT(setFontSize(int)));


    QHBoxLayout *hboxLayout = new QHBoxLayout;//上部分为一个水平布局
    hboxLayout->addWidget(dateLabel);
    hboxLayout->addWidget(monthCombo);
    hboxLayout->addWidget(yearEdit);
    hboxLayout->addSpacing(20);
    hboxLayout->addStretch(1);  //添加一个弹簧
    hboxLayout->addWidget(fontSizeLabel);
    hboxLayout->addWidget(sizeSpinBox);
    hboxLayout->addStretch(1);

    QVBoxLayout *vboxLayout = new QVBoxLayout;
    vboxLayout->addLayout(hboxLayout);
    centralWidget->setLayout(vboxLayout);

    setCentralWidget(centralWidget);


}

MainWindow::~MainWindow()
{

    delete ui;
}
void MainWindow::insertCalendar()
{

}
void MainWindow::setFontSize(const int &size)
{
    fontSize = size;
    insertCalendar();
}
void MainWindow::setMonth(const int &month)
{
    selectDate.setDate(selectDate.year(),month,selectDate.day());
    insertCalendar();
}
void MainWindow::setYear(const QDate &date)
{
    selectDate.setDate(date.year(),date.month(),date.day());
    insertCalendar();
}
