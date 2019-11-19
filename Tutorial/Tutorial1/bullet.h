#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsRectItem>

class Bullet: public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    Bullet();

signals:
    void IncreaseScore();
public slots:
    void Move();
};

#endif // BULLET_H
