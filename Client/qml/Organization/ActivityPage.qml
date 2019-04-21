import VPlayApps 1.0
import QtQuick 2.0

Page {
    id:activityPage

    NavigationBar{
        id:navigationbar
        leftBarItem: IconButtonBarItem{
            icon: IconType.backward
            onClicked: {
                activitypage.visible = false
                organization.visible = true
            }
        }
        rightBarItem: IconButtonBarItem{
            icon:IconType.list
            onClicked: {
                activitypage.visible = false
                memberlist.visible = true
            }
        }
    }

    Rectangle{
        id:introduction
        width: parent.width-dp(10)
        height: 1/4 * parent.height
        anchors.top: navigationbar.bottom
        anchors.topMargin: dp(5)
        anchors.horizontalCenter: parent.horizontalCenter
        border.width: dp(2)
//        color: "red"
        border.color: "lightgray"
        radius: dp(6)
        Text{
            id:introTitle
            text: qsTr("简介")
            font.pixelSize: sp(20)
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: dp(5)
        }
        Text{
            id:introContent
            width: parent.width - dp(2)*2
            text:qsTr("    篮球社成立于2014年，旨在聚集篮球爱好者一起锻炼身体、交流篮球技巧，提高篮球技术。")
            wrapMode: Text.WrapAnywhere
            lineHeight: 1.5
            font.pixelSize: sp(10)
            anchors.top: introTitle.bottom
            anchors.bottomMargin: dp(5)
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }
    Rectangle{
        id:activity1
        width: parent.width-dp(10)
        height: 1/4 * parent.height
        anchors.top: introduction.bottom
        anchors.topMargin: dp(10)
        anchors.horizontalCenter: parent.horizontalCenter
        border.color: "lightgray"
        border.width: dp(2)
        radius: dp(6)
        Text{
            id:title
            text: qsTr("动力精彩——篮球社与街舞社的VS")
            font.pixelSize: sp(20)
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: dp(5)
        }
        Text{
            id:activityIntro
            width: parent.width - dp(2)*2
            text:qsTr("    活动简介：本活动将于2019年3月12日9：00举办，地点：篮球场。本次活动中，篮球社成员将与街舞社成员分别表演节目，最后表演共同节目“动力精彩”。希望同学们到场观看。")
            wrapMode: Text.WrapAnywhere
            lineHeight: 1.5
            font.pixelSize: sp(10)
            anchors.top: title.bottom
            anchors.bottomMargin: dp(5)
            anchors.horizontalCenter: parent.horizontalCenter
        }
        AppButton{
            id:joinin
            width: dp(50)
            height: dp(20)
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            text: qsTr("参与")
            textSize: sp(15)
        }
    }
    AppButton{
        id:joinOrganization
        z:1
        width: dp(50)
        height: dp(20)
        anchors.bottom: parent.bottom
        anchors.bottomMargin: dp(20)
        anchors.horizontalCenter: parent.horizontalCenter
        text: qsTr("加入我们")
        textSize: sp(15)
    }
}
