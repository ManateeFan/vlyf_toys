#ifndef SPLITTERDEMO_H
#define SPLITTERDEMO_H

#include <QMainWindow>
#include "secdialog.h"
#include <QSharedPointer>

namespace Ui {
class SplitterDemo;
}

class SplitterDemo : public QMainWindow
{
    Q_OBJECT

public:
    explicit SplitterDemo(QWidget *parent = nullptr);
    ~SplitterDemo();

private slots:
    void on_pushButton_6_clicked();

private:
    Ui::SplitterDemo *ui;
    QSharedPointer<SecDialog> dialog;
};

#endif // SPLITTERDEMO_H
