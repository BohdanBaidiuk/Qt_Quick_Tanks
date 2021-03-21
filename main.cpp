//#include "item.h"
#include "game.h"

#include <QApplication>
//#include <QGraphicsScene>
//#include <QGraphicsItem>
//#include <QGraphicsView>
//#include <QApplication>
//#include <QTimer>

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();

    return a.exec();
}
