#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLineEdit>
#include <QStatusBar>
#include <QLabel>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void timerEvent(QTimerEvent*);
private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionRedo_triggered();

    void on_actionUndo_triggered();

    void on_actionAbout_me_triggered();

    void on_actionSave_as_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionBackgroundColor_triggered();

    void on_actionBackgroundColor_Edit_Text_triggered();

    void on_actionFind_triggered();

    void ShowFindText();
    void on_actionStatus_S_triggered();

private:
    Ui::MainWindow *ui;
    QString filePath;

    //FindDialog
    QDialog* findDialog;
    QLineEdit* findLineEdit;
    QStatusBar* statusBar;
    QLabel* statusLabel;
    QTimer* timer;
    QTextCursor cursor;
};

#endif // MAINWINDOW_H
