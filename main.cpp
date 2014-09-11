#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <ctime>

#include "minefield.h"
#include "minefieldmodel.h"

int main(int argc, char *argv[])
{
    // Set this to a number that gets an even number when sqrt.
    // That is: 16, 25, 36 ... 100 ... 144 ... 225 ... 900
    int noOfMinefields = 144;
    QGuiApplication app(argc, argv);

    srand(time(NULL));
    // MinefieldModel model;
    MinefieldModel model(&app, std::sqrt(noOfMinefields),std::sqrt(noOfMinefields));

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("minefieldModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // model.resize(std::sqrt(noOfMinefields),std::sqrt(noOfMinefields));

    model.debugContent();
    return app.exec();
}
