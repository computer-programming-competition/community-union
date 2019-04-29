import VPlayApps 1.0
import VPlay 2.0
import QtQuick 2.9
import client 1.0
App{
    onInitTheme: {
        Theme.platform = "ios"
    }
    property bool userLoggedIn: false
//    LoginPage {
//        z: 1 // show login above actual app pages
//        visible: opacity > 0
//        enabled: visible
//        opacity: userLoggedIn ? 0 : 1 // hide if user is logged in
//        onLoginSucceeded:{
//           console.debug("client")
//            client.logining(tUsername,tUserPassword)//交互C++，发送name和password
////            console.debug(client.userName)
////            console.debug(client.userPassword)

//            userLoggedIn = true
//        }

//        Behavior on opacity { NumberAnimation { duration: 250 } } // page fade in/out
//    }
    Client{
        id:client
    }


        Navigation{
            navigationMode: navigationModeTabsAndDrawer


            NavigationItem{
                title:"主页"
                icon:IconType.home
                Home{}//主页

            }
            NavigationItem{
                id:navigationIt
                title: "活动"
                icon:IconType.heart
                Activity{
                    id: activityy
                }
            }
            NavigationItem{
                title: "发布"
                icon:IconType.adn
                AddNew{}
            }
            NavigationItem{
                title: "消息"
                icon:IconType.medium
                Messagement{}
            }
            NavigationItem{
                title: "我的"
                icon:IconType.minussquareo
                Mine{}
            }

        }
    }
