//author: duHongpeng
//time: 19.4.16
import VPlayApps 1.0
import QtQuick.Controls 2.2 as Quick2
import QtQuick 2.0
import QtMultimedia 5.0
import activity 1.0

Item {
    anchors.fill: parent
NavigationStack{
    property int sourcePath: 1
    Page {
        id: page
        title: "活动"

        Activity1_0 {
            id: activity1_0
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
//                page.visible = false
//                page.focus = false
//                newActivityLoader.sourceComponent = newActivityComponent
//                navigationStack.push(newActivityComponent, {})

            }
        }

        Loader {
            id: newActivityLoader
            anchors.fill: parent
        }

        Component {
            id: newActivityComponent
            NewActivity {}
        }

        ListModel {
            id: listMo
            ListElement{
                time_text: "2019.04.01 ~ 2019.04.30"
                title_text: "青年之声：诗词大赛"
                label_text: "文体活动"
            }
        }

        Component {
            id: activityCo
            Rectangle {
                width: page.width
                height: 300

                Rectangle {
                    id: image
                    width: parent.width * 0.8
                    height: parent.width * 0.48
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: 10
                    color: "blue"
                }

                AppText {
                    id: time
                    text: time_text
                    color: "red"
                    anchors.top: image.bottom
                    anchors.topMargin: 10
                    anchors.left: image.left
                }

                AppText {
                    id: title
                    text: title_text
                    anchors.top: time.bottom
                    anchors.topMargin: 10
                    anchors.left: time.left
                }

                AppText {
                    id: label
                    text: label_text
                    anchors.top: title.bottom
                    anchors.topMargin: 10
                    anchors.left: title.left
                }
            }
        }

        Quick2.ScrollView {
            id: scrollView
            anchors.fill: parent

            ListView {
                model: listMo
                delegate: activityCo
            }
        }

    }

}
}
