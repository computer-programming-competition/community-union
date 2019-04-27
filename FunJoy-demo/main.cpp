#include <QApplication>
#include <VPApplication>
//#include "updatefile.h"
#include <QQmlApplicationEngine>
#include "recordervideo.h"
#include "client.h"
#include "activity.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    VPApplication vplay;

    // Use platform-specific fonts instead of V-Play's default font
//    qmlRegisterType<UploadAndDownload>("uploadAndDownload",1,0,"UploadAndDownload");//注册元对象系统
    qmlRegisterType<Client>("client",1,0,"Client");//客户端
    qmlRegisterType<RecorderVideo>("recordervideo",1,0,"RecorderVideo");
//    qmlRegisterType<Activity>("activity",1,0,"Activity1_0"); //huo dong
    vplay.setPreservePlatformFonts(true);

    QQmlApplicationEngine engine;
    vplay.initialize(&engine);

    // use this during development
    // for PUBLISHING, use the entry point below
    vplay.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    // vplay.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    engine.load(QUrl(vplay.mainQmlFileName()));

    return app.exec();
}
