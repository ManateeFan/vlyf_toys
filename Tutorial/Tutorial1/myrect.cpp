#include "myrect.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QTimer>

MyRect::MyRect()
{

    this->setBrush(QBrush(Qt::cyan));
    QTimer* timer = new QTimer(this);

    connect(timer, &QTimer::timeout, this, &MyRect::CreateEnemy);
    timer->start(1000);
}

void MyRect::CreateEnemy()
{
    Enemy* enemy = new Enemy();
    enemy->setBrush(QBrush(Qt::blue));
    enemy->setPos(rand() % 700, 0);
    this->scene()->addItem(enemy);
}

void MyRect::keyPressEvent(QKeyEvent* event)
{
    if(event->key() == Qt::Key_Left)
    {
        if(this->x() >= 0)
            setPos(x() - 10, y());
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(this->x() < (this->scene()->width() - this->rect().width()))
            setPos(x() + 10, y());
    }
    else if(event->key() == Qt::Key_Space)
    {
        // create a bullet
        Bullet* bullet = new Bullet();
        bullet->setBrush(QBrush(Qt::red));
        bullet->setPos(x(), y());
        this->scene()->addItem(bullet);
    }
}
