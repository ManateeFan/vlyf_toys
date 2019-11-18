#include "splitterdemo.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SplitterDemo w;
    w.show();

    return a.exec();
}
