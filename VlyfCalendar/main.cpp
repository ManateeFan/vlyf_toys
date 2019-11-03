#include "vlyfcalendar.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VlyfCalendar w;
    w.show();

    return a.exec();
}
