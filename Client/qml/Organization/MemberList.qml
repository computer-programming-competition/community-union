import VPlayApps 1.0
import QtQuick 2.0
import QtQuick.Layouts 1.1

Page {
    id:memberlist
    NavigationBar{
        id:navigationbar
        leftBarItem: IconButtonBarItem{
            icon: IconType.backward
            onClicked: {
                activitypage.visible = true
                memberlist.visible = false
            }
        }
    }
    ColumnLayout{
        id:list
        spacing: 1
        width: parent.width
        height: parent.height
        anchors.top: navigationbar.bottom
        anchors.topMargin: dp(10)
        anchors.horizontalCenter: parent.horizontalCenter
        Rectangle{
            id:list1
            width: parent.width
            height: parent.height * 1/16
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            border.width: dp(2)
            border.color: "lightgray"
            radius: dp(2)
            Text {
                id: name1
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("社长   张三")
            }
        }
        Rectangle{
            id:list2
            width: parent.width
            height: parent.height * 1/16
            anchors.top: list1.bottom
            anchors.topMargin: dp(1)
            anchors.horizontalCenter: parent.horizontalCenter
            border.width: dp(2)
            border.color: "lightgray"
            radius: dp(2)
            Text {
                id: name2
                anchors.verticalCenter: parent.verticalCenter
                text: qsTr("副社长  王梅")
            }
        }
   }
}
