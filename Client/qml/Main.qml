//import VPlayApps 1.0
//import VPlay 2.0
import QtQuick 2.9
import Felgo 3.0
import client 1.0
import "logic"
import "model"
import user 1.0
//import "Custom suite"
import "Organization"

App{
    onInitTheme: {
        Theme.platform = "andriod"
    }
    //property bool NetState: false
    Client{
        id:client
    }



    User{
        id:user


    }


    property bool userLoggedIn: false
    Logic {
        id: logic
    }

    DataModel {
        id: dataModel
        dispatcher: logic // data model handles actions sent by logic

        // global error handling
        onFetchTodosFailed: nativeUtils.displayMessageBox("Unable to load todos", error, 1)
        onFetchTodoDetailsFailed: nativeUtils.displayMessageBox("Unable to load todo "+id, error, 1)
        onStoreTodoFailed: nativeUtils.displayMessageBox("Failed to store "+viewHelper.formatTitle(todo))
    }
    LoginPage {
        z: 1 // show login above actual app pages
        visible: opacity > 0
        enabled: visible
        opacity: userLoggedIn ? 0 : 1 // hide if user is logged in
        onLoginSucceeded:{
           console.debug("client")
            //client.login()
           // client.logining(tUsername,tUserPassword)//交互C++，发送name和password
//            console.debug(client.userName)
//            console.debug(client.userPassword)
            if(client.loginok)
            {
                userLoggedIn = 1
            }


        }

        Behavior on opacity { NumberAnimation { duration: 250 } } // page fade in/out
    }

   MainPage{

   }

}
