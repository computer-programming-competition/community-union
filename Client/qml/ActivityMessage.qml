import VPlayApps 1.0
import VPlay 2.0
import QtQuick.Controls 2.2 as Quick2
import QtQuick 2.0
import QtMultimedia 5.0

Page {
    title: "活动详情"
    property string time_text_text
    property string title_text_text
    property string label_text_text
    property string content_text_text

    Rectangle {
        id: image
        width: parent.width
        height: parent.width * 0.48
//        color: "blue"
        Image {
            id: activityimage
            width: parent.width
            height: parent.height
            anchors.left: parent.left
            anchors.top: parent.top
            source: "../qml/Image/chongshitushuguan.jpg"
        }
//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                listmodel.append({"time_text":time_text_text, "title_text":title_text_text, "label_text":label_text_text, "content_text":content_text_text})
//            }
//        }
    }

//    ListModel {
//        id: listmodel
////        ListElement{
////            time_text: "fds"
////            title_text: "sa"
////            label_text: "fd"
////            content_text: "d"
////        }
//    }

//    Component {
//        id: component
//        Rectangle {
//            width: page.width
//            height: titleLabel.height + timeLabel.height + labelLabel.height + content.height + 50

//            AppText {
//                id: titleLabel
//                text: "zhuti"
//                anchors.top: parent.top
//                anchors.topMargin: 10
//                anchors.left: parent.left
//                anchors.leftMargin: 20
//            }

//            AppText {
//                id: title
//                text: title_text
//                anchors.top: titleLabel.top
//                anchors.left: titleLabel.right
//                anchors.leftMargin: 10
//            }

//            AppText {
//                id: timeLabel
//                text: "shijian"
//                anchors.top: titleLabel.bottom
//                anchors.topMargin: 10
//                anchors.left: titleLabel.left
//            }

//            AppText {
//                id: time
//                text: time_text
//                anchors.top: timeLabel.top
//                anchors.left: timeLabel.right
//                anchors.leftMargin: 10
//            }

//            AppText {
//                id: labelLabel
//                text: "biaoqian"
//                anchors.top: timeLabel.bottom
//                anchors.topMargin: 10
//                anchors.left: timeLabel.left
//            }

//            AppText {
//                id: label
//                text: label_text
//                anchors.top: labelLabel.top
//                anchors.left: labelLabel.right
//                anchors.leftMargin: 10
//            }

//            AppText {
//                id: content
//                text: content_text
//                anchors.top: labelLabel.bottom
//                anchors.topMargin: 10
//                anchors.left: labelLabel.left
//            }
//        }
//    }

    Rectangle {
        width: parent.width
        height: parent.height - image.height
        anchors.top: image.bottom
        anchors.topMargin: 10

        AppText {
            id: titleLabel
            text: "活动主题^"
            anchors.top: parent.top
            anchors.topMargin: 10
            anchors.left: parent.left
            anchors.leftMargin: 20
        }

        AppText {
            id: title
            text: title_text_text
            anchors.top: titleLabel.top
            anchors.left: titleLabel.right
            anchors.leftMargin: 10
        }

        AppText {
            id: timeLabel
            text: "活动时间"
            anchors.top: titleLabel.bottom
            anchors.topMargin: 10
            anchors.left: titleLabel.left
        }

        AppText {
            id: time
            text: time_text_text
            anchors.top: timeLabel.top
            anchors.left: timeLabel.right
            anchors.leftMargin: 10
        }

        AppText {
            id: labelLabel
            text: "标签"
            anchors.top: timeLabel.bottom
            anchors.topMargin: 10
            anchors.left: timeLabel.left
        }

        AppText {
            id: label
            text: label_text_text
            anchors.top: labelLabel.top
            anchors.left: labelLabel.right
            anchors.leftMargin: 10
        }

        AppText {
            id: content
            width: parent.width * 0.9
            text: content_text_text
            anchors.top: labelLabel.bottom
            anchors.topMargin: 10
            anchors.left: labelLabel.left
        }
        AppButton {
            id: button
            z:2
            text: "参与"
            flat: false
            radius: 90

            anchors.horizontalCenter: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 30

            onClicked: {
                button.backgroundColor = "lightgray"
            }
        }
//        Quick2.ScrollView {
//            id: scrollView
//            anchors.fill: parent

//            ListView {
//                model: listmodel
//                delegate: component
//            }
//        }
    }
}
