#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "minefield.h"
#include "minefieldmodel.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    MinefieldModel model;

    int i = 0;
    while (i < 25)
    {
        model.addMinefield(Minefield("test", "test2"));
        i++;
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("minefieldModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
