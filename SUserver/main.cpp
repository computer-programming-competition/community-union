#include <QApplication>
#include <FelgoApplication>

#include <QQmlApplicationEngine>

// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>
#include <QApplication>
#include <VPApplication>

#include <QQmlApplicationEngine>
#include "server.h"

int main(int argc, char *argv[])
{

    Server service;
    service.connect();
}

