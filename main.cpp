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

    // TODO: Create Board
    Board board = Board(5, 5);

    // TODO: Create BoardModel
    BoardModel boardModel = BoardModel(&board);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("boardModel", &boardModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
