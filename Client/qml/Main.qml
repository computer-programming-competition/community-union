import VPlayApps 1.0
import VPlay 2.0
import QtQuick 2.9
import client 1.0
import "Custom suite"
import "Organization"
App{
    onInitTheme: {
        Theme.platform = "andriod"
    }
    //property bool NetState: false
    /*Client{
        id:client


    }*/

    MsgDialog{

    }
    property bool userLoggedIn: false
    /*LoginPage {
        z: 1 // show login above actual app pages
        visible: opacity > 0
        enabled: visible
        opacity: userLoggedIn ? 0 : 1 // hide if user is logged in
        onLoginSucceeded:{
           console.debug("client")
            client.logining(tUsername,tUserPassword)//交互C++，发送name和password
//            console.debug(client.userName)
//            console.debug(client.userPassword)

            userLoggedIn = true
        }

        Behavior on opacity { NumberAnimation { duration: 250 } } // page fade in/out
    }*/

    MainPage{

    }

}
