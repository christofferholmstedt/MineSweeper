#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "minefield.h"
#include "minefieldmodel.h"

int main(int argc, char *argv[])
{
    // Set this to a number that gets an even number when sqrt.
    // That is: 16, 25, 36 ... 100 ... 144 ... 225 ... 900
   // int noOfMinefields = 144;
    QGuiApplication app(argc, argv);
    // MinefieldModel model(100);
    MinefieldModel model;

//    int i = 0;
//    int randomNumber;
//    bool hasMine;
//    while (i < noOfMinefields)
//    {
//        randomNumber = rand() % 2;
//        if (randomNumber == 0)
//        {
//            hasMine = false;
//        }
//        else
//        {
//            hasMine = true;
//        }
//        model.addMinefield(Minefield(hasMine));
//        i++;
//    }

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("minefieldModel", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
