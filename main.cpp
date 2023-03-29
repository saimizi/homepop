#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "homepop.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

	/* This is expected to be used as app-id in Wayland */
	app.setApplicationDisplayName("sys.app.homepop");

    qmlRegisterType<HomePop>("HomePopApp", 1, 0, "HomePop");

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
