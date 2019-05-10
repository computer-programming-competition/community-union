//guchangrong
//学生的社团列表
import VPlayApps 1.0
import QtQuick 2.0
import QtQuick.Layouts 1.1
import ".."
Page {
    id:memberlist
    title: "成员列表"

    ListModel {
        id: listMo
        ListElement {
            zhicheng: "成员"
            name: "李四"
            score: "10"
        }
    }

    Component {
        id: activityCo
        Rectangle{
            width: memberlist.width
            height: memberlist.height * 1/16
            border.width: dp(2)
            border.color: "lightgray"
            radius: dp(2)
            RowLayout {
                width: parent.width
                height: parent.height
                spacing: 3
                Text {
                    id: name1
                    text: zhicheng
                }
                Text {
                    id: name2
                    text: name
                }
                Text {
                    id: name3
                    text: score
                }
            }
        }
    }

    ListView {
        anchors.fill: parent
        model: listMo
        delegate: activityCo
    }

//    ColumnLayout{
//        id:list
//        spacing: 2
//        width: parent.width
//        height: parent.height
//        anchors.top: navigationbar.bottom
//        anchors.topMargin: dp(10)
//        anchors.horizontalCenter: parent.horizontalCenter
//        Rectangle{
//            id:list1
//            width: parent.width
//            height: parent.height * 1/16
//            anchors.top: parent.top
//            anchors.horizontalCenter: parent.horizontalCenter
//            border.width: dp(2)
//            border.color: "lightgray"
//            radius: dp(2)
//            Text {
//                id: name1
//                anchors.verticalCenter: parent.verticalCenter
//                text: qsTr("社长   张三    10")
//            }
//        }
//        Rectangle{
//            id:list2
//            width: parent.width
//            height: parent.height * 1/16
//            anchors.top: list1.bottom
//            anchors.topMargin: dp(1)
//            anchors.horizontalCenter: parent.horizontalCenter
//            border.width: dp(2)
//            border.color: "lightgray"
//            radius: dp(2)
//            Text {
//                id: name2
//                anchors.verticalCenter: parent.verticalCenter
//                text: qsTr("副社长  王梅  9")
//            }
//        }
//   }
}
