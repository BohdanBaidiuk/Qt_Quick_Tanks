#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSurfaceFormat>
#include "object/object.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);


    QSurfaceFormat format = QSurfaceFormat::defaultFormat();
    format.setSamples(16);
    QSurfaceFormat::setDefaultFormat(format);

    qmlRegisterType<Object>("Object", 1, 0, "Object");


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

       QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                        &app, [url](QObject *obj, const QUrl &objUrl) {
           if (!obj && url == objUrl)
               QCoreApplication::exit(-1);
       }, Qt::QueuedConnection);
       engine.load(url);


    return app.exec();
}
