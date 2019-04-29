//蒋富豪 2018-1-5
#include <QApplication>
#include <VPApplication>

#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    TcpServer tcpserver;
    return app.exec();
}
