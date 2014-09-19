#include <cstdlib>
#include <ctime>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QtWidgets/QWidget>
#include <QQmlComponent>
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
    BoardModel boardModel(&board);
    engine.rootContext()->setContextProperty("boardModel", &boardModel);

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject * mainQmlWindow = engine.rootObjects().at(0);

    QObject::connect(mainQmlWindow, SIGNAL(squareClicked(int,bool)),
                     &boardModel, SLOT(squareClickedSlot(int,bool)));

    return app.exec();
}
