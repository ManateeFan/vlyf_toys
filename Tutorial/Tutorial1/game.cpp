#include "game.h"

Game::Game(QWidget *parent): QGraphicsView (parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    rect = new MyRect();
    rect->setRect(0, 0, 100, 100);
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();
    rect->setPos(this->width() / 2, this->height());
    scene->addItem(rect);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(800, 600);

    setScene(scene);
    setBackgroundBrush(QBrush(QPixmap(":/img/plasma-5-10-cascade-4k.png")));
    this->show();
}
