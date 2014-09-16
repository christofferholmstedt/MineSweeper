#include <cstdlib>
#include <ctime>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtWidgets/QWidget>
#include <QDebug>

#include "square.h"
#include "board.h"
#include "boardmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    /* initialize random seed: */
    srand(time(NULL));

    Board board = Board(10, 10);
    BoardModel boardModel = BoardModel(&board);
    engine.rootContext()->setContextProperty("boardModel", &boardModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *item = engine.rootObjects().at(0);

    QList<QObject *> rect = item->findChildren<QObject *>("root");
//    if (rect)
//        rect->setProperty("color", "red");

    // qDebug() << rect;
    // QList<QWidget *> widgetList = item->findChildren<QWidget *>();

    // The signal is available in the children "square" not in the root element
    // so I need to access all children and connect respective signal to the one slot
    // in the BoardModel. If I move slot to root object in main.qml it all works between
    // c++ and qml but not within qml code (square.qml can't cool there parent in another
    // qml file).
    QObject::connect(item, SIGNAL(isVisitedSignal(int,bool)),
                     &boardModel, SLOT(isVisitedSlot(int,bool)));

    return app.exec();
}
