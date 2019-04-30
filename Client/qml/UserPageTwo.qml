import QtQuick 2.0
import Felgo 3.0

Page {
    Rectangle{
        anchors.top:parent.top
        Column{
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 5
            spacing: 5
            AppButton {
                id: button
                z:2
                text: "我的社团"
                flat: false
                radius: 90

                //anchors.horizontalCenter: parent.horizontalCenter
                //anchors.bottom: parent.bottom
                //        anchors.bottomMargin: 30

                onClicked: {
                    userpage.navigationStack.push(settingsPage)
                }
            }
            AppButton {
                id: button2
                z:2
                text: "我的活动"
                flat: false
                radius: 90

                //        anchors.horizontalCenter: parent.horizontalCenter
                //anchors.bottom: parent.bottom
                //        anchors.bottomMargin: 30

                onClicked: {
                    userpage.navigationStack.push(settingsPage)
                }
            }
        }
    }

}
