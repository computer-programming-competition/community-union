//author: duHongpeng
//time: 19.4.16
import VPlayApps 1.0
import QtQuick.Controls 2.2 as Quick2
import QtQuick 2.0
import QtMultimedia 5.0


Page {
    id: page
    title: "活动"
    property alias listMo: listMo

    Connections {
        target: client
        onReleaseActivity: {
            console.log("ff")
            listMo.append({"time_text":time, "title_text":title, "label_text":label, "content_text":content})
        }
    }

    Connections {
        target: client
        onClearActivity: {
            console.log("clear")
            listMo.clear()
        }
    }
    Component {
        id: newActivityComponent
        NewActivity {}
    }

    Component {
        id: activityMessageCom
        ActivityMessage {}
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
            page.navigationStack.push(newActivityComponent)
        }
    }

    Loader {
        id: newActivityLoader
        anchors.fill: parent
    }



    ListModel {
        id: listMo
//        ListElement{
//            time_text: "2019.04.01 ~ 2019.04.30"
//            title_text: "青年之声：诗词大赛"
//            label_text: "文体活动"
//            content_text: "fdsaf"
//        }
    }

    Component {
        id: activityCo
        Rectangle {
            width: page.width
            height: image.height + time.height + title.height + label.height + 50

            Rectangle {
                id: image
                width: parent.width * 0.8
                height: parent.width * 0.48
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: parent.top
                anchors.topMargin: 10
                color: "blue"

                MouseArea {
                    anchors.fill: parent
                    onClicked: {
                        page.navigationStack.push(activityMessageCom, {
                                                      time_text_text: time_text,
                                                      title_text_text: title_text,
                                                      label_text_text: label_text,
                                                      content_text_text: content_text
                                                  })
                    }
                }
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

