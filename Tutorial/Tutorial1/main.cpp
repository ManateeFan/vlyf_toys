#include <QApplication>
#include <QGraphicsScene>
#include "game.h"

#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    // create a scene
//    QGraphicsScene* scene = new QGraphicsScene();

//    // create an item to put into the scene
//    MyRect* rect = new MyRect();
//    //x, y, w, h
//    rect->setRect(0, 0, 100, 100);

//    // add the item to the scene
//    scene->addItem(rect);

//    // make rect focusable
//    rect->setFlag(QGraphicsItem::ItemIsFocusable);
//    rect->setFocus();
//    // add a view
//    QGraphicsView* view = new QGraphicsView(scene);
//    // view->setScene(scene);


//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


//    // show the view

//    view->setFixedSize(800, 600);
//    scene->setSceneRect(0, 0, 800, 600);



//    rect->setPos(view->width() / 2, view->height() - rect->rect().height());




//    view->show();
    Game* game = new Game();
    game->setWindowTitle("GeniusVlyf");
    return a.exec();
}
