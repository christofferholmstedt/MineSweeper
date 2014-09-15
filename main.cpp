#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

#include "square.h"
#include "board.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // TODO: Create Square
    Square square_ = Square(2);

    // TODO: Create Board
    Board board_ = Board(square_, 5, 5);

    // TODO: Create BoardModel

    QQmlApplicationEngine engine;
    // engine.rootContext()->setContextProperty("BoardModel", &boardModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
