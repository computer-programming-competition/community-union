//guchangrong
//管理员页面，显示社团列表和发布活动
import VPlayApps 1.0
import QtQuick 2.0
import QtQuick.Layouts 1.1
import ".."
Page {
    id:memberlist
    title: "管理员页面"

    Component {
        id: newActivityComponent

           NewActivity {}

    }

    AppButton {
        id: button
        z:2
        text: "+活动"
        flat: false
        radius: 90

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30

        onClicked: {
            userpage.navigationStack.push(newActivityComponent)
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
                text: qsTr("社长   张三    10")
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
                text: qsTr("副社长  王梅    9")
            }
        }
   }
}
