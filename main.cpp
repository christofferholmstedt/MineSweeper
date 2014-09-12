#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // TODO: Create Square

    // TODO: Create Board

    // TODO: Create BoardModel

    QQmlApplicationEngine engine;
    // engine.rootContext()->setContextProperty("BoardModel", &boardModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
