#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QFont>
#include <QColorDialog>
#include <QColor>
#include <QLabel>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textEdit->setFont(QFont("微软雅黑", 12));
    setWindowIcon(QIcon(":/rec/img/me.jfif"));
    setCentralWidget(ui->textEdit);
    setWindowTitle("GeniusVlyf Notepad");

    //status Bar
    timer = new QTimer;
    statusBar = new QStatusBar(this);
    cursor = ui->textEdit->textCursor();
    statusLabel = new QLabel("第"+QString::number(cursor.blockNumber()+1)+"行,第"+QString::number(cursor.columnNumber()+1)+"列",statusBar);
    statusBar->addWidget(statusLabel);
    setStatusBar(statusBar);
    timer->start(1);
    //Set findDialog
    findDialog = new QDialog(this);
    findDialog->setWindowTitle("查找");
    QHBoxLayout* findDialogLayout = new QHBoxLayout(findDialog);

    QHBoxLayout* findLabelLine = new QHBoxLayout(findDialog);

    QLabel* findLabel = new QLabel("查找文本:", findDialog);
    findLineEdit = new QLineEdit(findDialog);
    findLabelLine->addWidget(findLabel);
    findLabelLine->addWidget(findLineEdit);
    QVBoxLayout* findBtnLayout = new QVBoxLayout(findDialog);
    QPushButton* btnFindNext = new QPushButton("查找下一个", findDialog);
    QPushButton* btnFindCancle = new QPushButton("取消", findDialog);
    findBtnLayout->addWidget(btnFindNext);
    findBtnLayout->addWidget(btnFindCancle);

    findDialogLayout->addLayout(findLabelLine);
    findDialogLayout->addLayout(findBtnLayout);
    connect(btnFindNext, &QPushButton::clicked, this, &MainWindow::ShowFindText);
    connect(btnFindCancle, &QPushButton::clicked, findDialog, &QDialog::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *)
{
    cursor = ui->textEdit->textCursor();
    statusLabel->setText("第"+QString::number(cursor.blockNumber()+1)+"行,第"+QString::number(cursor.columnNumber()+1)+"列");
    statusBar->addPermanentWidget(statusLabel);
}

void MainWindow::on_actionNew_triggered()
{
    filePath = "";
    ui->textEdit->setText("");
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,"Open the file");
    QFile file(fileName);
    filePath = fileName;
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","file not open!");
        return;
    }
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(filePath);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","file not open!");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"..","file not open!");
        return;
    }
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_me_triggered()
{
    QString aboutText;
    aboutText = "Auther : GeniusVlyf\n";
    aboutText += "Date  : 18/11/2019\n";
    aboutText += "(C) NotePade (R)\n";
    QMessageBox::about(this,"About",aboutText);

}


void MainWindow::on_actionFont_triggered()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
    {
        ui->textEdit->setFont(font);
    }
    else return;
}

void MainWindow::on_actionColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if(color.isValid())
    {
        ui->textEdit->setTextColor(color);
    }
}

void MainWindow::on_actionBackgroundColor_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if(color.isValid())
    {
        ui->textEdit->setTextBackgroundColor(color);
    }
}

void MainWindow::on_actionBackgroundColor_Edit_Text_triggered()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Choose Color");
    if(color.isValid())
    {
        ui->textEdit->setPalette(QPalette(color));
    }
}

// show findDialog
void MainWindow::on_actionFind_triggered()
{
    findDialog->show();
}



void MainWindow::ShowFindText()
{
    QString findText = findLineEdit->text();
    if(!ui->textEdit->find(findText,QTextDocument::FindBackward))
    {
        QMessageBox::warning(findDialog, "未找到", "找不到" + QString('"') + findText + QString('"') );
    }
}

void MainWindow::on_actionStatus_S_triggered()
{
    if(!ui->actionStatus_S->isChecked())
        this->statusBar->hide();
    else
        this->statusBar->show();
}
