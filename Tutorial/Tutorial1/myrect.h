#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include <QKeyEvent>

class MyRect: public QGraphicsRectItem, public QObject
{
public:
    MyRect();

    void keyPressEvent(QKeyEvent* event);

public slots:
    void CreateEnemy();
};


#endif // MYRECT_H
