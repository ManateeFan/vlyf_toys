#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

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
    void push_btn_clicked();
    void clear_btn_clicked();
    void action_about_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
