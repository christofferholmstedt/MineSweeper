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
    int randomNumber;
    bool hasMine;
    while (i < 25)
    {
        randomNumber = rand() % 2;
        if (randomNumber == 0)
        {
            hasMine = false;
        }
        else
        {
            hasMine = true;
        }
        model.addMinefield(Minefield(hasMine));
        i++;
    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("minefieldModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
