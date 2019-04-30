#include <QApplication>
#include <FelgoApplication>

#include <QQmlApplicationEngine>
#include "client.h"
#include "activity.h"
#include "useroperation.h"
#include "community.h"
#include "communityitem.h"
// uncomment this line to add the Live Client Module and use live reloading with your custom C++ code
//#include <FelgoLiveClient>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    FelgoApplication felgo;

    // Use platform-specific fonts instead of Felgo's default font
    felgo.setPreservePlatformFonts(true);
     qmlRegisterType<Client>("client",1,0,"Client");//客户端
     qmlRegisterType<UserOperation>("user",1,0,"User");
     qmlRegisterType<Activity>("activity",1,0,"Activity1_0"); //huo dong
     qmlRegisterType<MyCommunity>("community",1,0,"Community");
     qmlRegisterType<communityItem>("communityitem",1,0,"CommunityItem");
    QQmlApplicationEngine engine;
    felgo.initialize(&engine);

    // use this during development
    // for PUBLISHING, use the entry point below
    felgo.setMainQmlFileName(QStringLiteral("qml/Main.qml"));

    // use this instead of the above call to avoid deployment of the qml files and compile them into the binary with qt's resource system qrc
    // this is the preferred deployment option for publishing games to the app stores, because then your qml files and js files are protected
    // to avoid deployment of your qml files and images, also comment the DEPLOYMENTFOLDERS command in the .pro file
    // also see the .pro file for more details
    // felgo.setMainQmlFileName(QStringLiteral("qrc:/qml/Main.qml"));

    engine.load(QUrl(felgo.mainQmlFileName()));

    // to start your project as Live Client, comment (remove) the lines "felgo.setMainQmlFileName ..." & "engine.load ...",
    // and uncomment the line below
    //FelgoLiveClient client (&engine);

    return app.exec();
}
