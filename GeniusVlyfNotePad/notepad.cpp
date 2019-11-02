#include "notepad.h"
#include "ui_notepad.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QLabel>
#include <QDialog>
#include <QColorDialog>
#include <QFontDialog>

NotePad::NotePad(QWidget *parent) : QMainWindow(parent),
                                    ui(new Ui::NotePad)
{
    ui->setupUi(this);
    ui->statusBar->addPermanentWidget(new QLabel("Vlyf: Welcome to use my NotePad!\t"));
    this->setWindowIcon(QIcon(":/image/me.jfif"));
    this->setWindowTitle("GeniusVlyf NotePad");

    connect(ui->actionNew, &QAction::triggered, this, &NotePad::newDocument);
    connect(ui->actionOpen, &QAction::triggered, this, &NotePad::open);

    connect(ui->actionAbout_2, &QAction::triggered, this, &NotePad::about);
    connect(ui->actionCopy, &QAction::triggered, this, &NotePad::copy);
    connect(ui->actionCut, &QAction::triggered, this, &NotePad::cut);
    connect(ui->actionPaste, &QAction::triggered, this, &NotePad::paste);
    connect(ui->actionUndo, &QAction::triggered, this, &NotePad::undo);
    connect(ui->actionRedo, &QAction::triggered, this, &NotePad::redo);
    connect(ui->actionFontColor, &QAction::triggered, this, &NotePad::font_color);
    connect(ui->actionFont, &QAction::triggered, this, &NotePad::font);
    connect(ui->actionExit, &QAction::triggered, this, &NotePad::exit);
}

NotePad::~NotePad()
{
    delete ui;
}
//新建文件
void NotePad::newDocument()
{
    /*如果文件还未保存
    if(ui->textEdit->document())
    {
        if(QMessageBox::Save==QMessageBox::question(this,"警告","文件未保存，是否保存？"))
            保存文件
        else
            ui->textEdit->setText(QString());
    }
    */
}
//打开文件
void NotePad::open()
{
    QString fileName = QFileDialog::getOpenFileName(this, "选择文件");
    QFile file(fileName);
    currentFile = fileName;
    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "警告", "无法打开文件:" + file.errorString());
        return;
    }
    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    ui->textEdit->setText(text);
    file.close();
}
//拷贝
void NotePad::copy()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->copy();
#endif
}
//剪切
void NotePad::cut()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->cut();
#endif
}
//粘贴
void NotePad::paste()
{
#if QT_CONFIG(clipboard)
    ui->textEdit->paste();
#endif
}
//undo
void NotePad::undo()
{
    ui->textEdit->undo();
}
//redu
void NotePad::redo()
{
    ui->textEdit->redo();
}
//退出
void NotePad::exit()
{
    QCoreApplication::quit();
}
//字体加粗
void NotePad::font()
{
    bool ok;
    QFont f = QFontDialog::getFont(&ok, this);
    ui->textEdit->setFont(f);
}
//字体颜色
void NotePad::font_color()
{
    QColor color = QColorDialog::getColor(QColor(255, 0, 0), this);

    ui->textEdit->setTextColor(color);
    ui->textEdit->setText(ui->textEdit->toPlainText());
}
//关于
void NotePad::about()
{
    QMessageBox::about(this, "关于", "欢迎使用GeniusVlyf NotePad，功能待完善。\n\n"
                                     "                              2019.11.2\n"
                                     "                              By vlyf\n");
}
