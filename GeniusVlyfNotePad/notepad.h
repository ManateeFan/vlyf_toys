#ifndef NOTEPAD_H
#define NOTEPAD_H

#include <QMainWindow>

namespace Ui
{
class NotePad;
}

class NotePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit NotePad(QWidget *parent = nullptr);
    ~NotePad();

private slots:
    void newDocument();
    void open();

    void font_color();
    void font();
    void copy();
    void cut();
    void paste();
    void undo();
    void redo();
    void exit();
    /*

    void save();
    void saveAS();
    void print();
    */
    void about();

private:
    Ui::NotePad *ui;
    QString currentFile;
};

#endif // NOTEPAD_H
