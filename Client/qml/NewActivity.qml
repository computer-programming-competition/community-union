import VPlayApps 1.0
import VPlay 2.0
import QtQuick.Controls 2.2 as Quick2
import QtQuick 2.0
import QtMultimedia 5.0

Page {
    Rectangle {
        id: rectangleTop
        width: parent.width
        height: parent.height*0.85

        ScrollViewVPlay {
            anchors.fill: parent
            clip: true

//            Quick2.Label {
//                      text: "ABC"
//                      font.pixelSize: 600
//            }
            Column{

                AppText {
                    id: titleText
                    text: "主题"
                    x: 20
                }
                AppTextField {
                    id: titleTextEdit
                    x: 20
                    y: 30
                    borderWidth: 0.5

                }
                AppText {
                    id: timeText
                    x: 20
                    y: 80
                    text: "活动时间"
                }
                AppTextField {
                    id: timeTextEdit
                    x: 20
                    y: 110
                    borderWidth: 0.5
                }
                AppText {
                    id: label
                    x: 20
                    y: 160
                    text: "活动标签"
                }
                AppTextField {
                    id: labelTextEdit
                    x: 20
                    y: 190
                    borderWidth: 0.5
                }

                AppText {
                    id: contentText
                    x: 20
                    y: 240
                    text: "主要内容"
                }

                ScrollViewVPlay {
                    width: 300
                    height: 200
                    x: 20
                    y: 270
                    Quick2.TextArea {
                        id: contentTextEdit
                        text: "fasfasdfasdfasfsdfadsf"
                    }
                }
            }

//            Rectangle {
//                x: 20
//                y: 270
//                color: "red"
//                width: parent.width * 0.6
//                height: 200
//                border.width: 1
//                Quick2.ScrollView {
//                    anchors.fill: parent
//                    Quick2.TextArea {
//                        id: contentTextEdit
//                        text: "fasfasdfasdfasfsdfadsf"
//                    }
//                }
//            }
        }
    }


    Rectangle {
        width: parent.width
        height: parent.height * 0.15
        anchors.top: rectangleTop.bottom

        AppButton {
            id: sureButton

            text: "提交"
            flat: false
            radius: 90

            anchors.horizontalCenter: parent.horizontalCenter
//            anchors.bottom: parent.bottom
//            anchors.bottomMargin: 30

            onClicked: {
//                activity1_0.title = titleTextEdit.text
//                activity1_0.time = timeTextEdit.text
//                activity1_0.label = labelTextEdit.text
//                activity1_0.content = contentTextEdit.text
//                activity1_0.setNewActivity(titleTextEdit.text, timeTextEdit.text, labelTextEdit.text, contentTextEdit.text)
                client.sendActivity(titleTextEdit.text, timeTextEdit.text, labelTextEdit.text, contentTextEdit.text)
            }
        }
    }
}
