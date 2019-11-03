#ifndef VLYFCALENDAR_H
#define VLYFCALENDAR_H

#include <QMainWindow>

namespace Ui {
class VlyfCalendar;
}

class VlyfCalendar : public QMainWindow
{
    Q_OBJECT

public:
    explicit VlyfCalendar(QWidget *parent = nullptr);
    ~VlyfCalendar();
private slots:
    void AboutActionTriggered();
private:
    Ui::VlyfCalendar *ui;
};

#endif // VLYFCALENDAR_H
