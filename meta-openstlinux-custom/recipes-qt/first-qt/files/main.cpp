#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    // ŁADOWANIE QML Z DYSKU
    engine.load(QUrl("file:///usr/share/first-qt/qml/main.qml"));

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}

