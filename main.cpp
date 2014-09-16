#include <cstdlib>
#include <ctime>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
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

    return app.exec();
}
