#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QTextBrowser>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void setFontSize(const int &size);
    void setMonth(const int &month);
    void setYear(const QDate &date);

private:
    Ui::MainWindow *ui;
    void insertCalendar();
    int fontSize;
    QDate selectDate;
    QTextBrowser *editor;   //下拉列表
};

#endif // MAINWINDOW_H
