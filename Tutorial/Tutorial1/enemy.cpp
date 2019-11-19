#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
Enemy::Enemy()
{
    int x = rand() % 700;
    setRect(x, 0, 50, 50);

    QTimer* timer = new QTimer();

    connect(timer, &QTimer::timeout, this, &Enemy::Move);
    timer->start(50);
}

void Enemy::Move()
{
    setPos(this->x(), this->y() + 5);
    if(this->y() > this->scene()->height())
    {
        this->scene()->removeItem(this);
        delete this;
    }

}
