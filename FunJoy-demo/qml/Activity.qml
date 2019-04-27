//author: duHongpeng
//time: 19.4.16
import VPlayApps 1.0
import QtQuick.Controls 2.2 as Quick2
import QtQuick 2.0
import QtMultimedia 5.0
//import activity 1.0

Item {
    property alias listMo: listMo
    anchors.fill: parent
NavigationStack{
    property int sourcePath: 1

    Page {
        id: page
        title: "活动"
//        Rectangle{
//            color: "red"
//            width: 200
//            height: 200
//            z:2
//            anchors.bottom: parent.bottom
//            anchors.horizontalCenter: parent.Center
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    console.log("滑动到了--------"+swipeView.currentIndex)
//                }
//            }
//        }



//        Activity1_0 {
//            id: activity1_0
//        }

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
                listMo.append({"time_text":"1", "title_text":"2", "label_text":"3"})
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

//        Quick2.SwipeView {
//            id: swipeView
//            width: parent.width
//            height: parent.height
//            orientation: "Vertical"
//            Rectangle { color: "green"  }
//            Rectangle { color: "black"
//                MouseArea{
//                    anchors.fill: parent
//                    onPressed: {
//                        mediaplayer.pause()
//                        pauseAndPlayButton.visible = true
//                    }
//                }
//                VideoOutput {
//                    anchors.fill: parent
//                    source: mediaplayer
//                }
//                AppButton{
//                    id:pauseAndPlayButton
//                    icon: IconType.play
//                    anchors.centerIn: parent
//                    visible: mediaplayer.status
//                    onClicked: {
//                        visible = false
//                        mediaplayer.play()
//                    }
//                }
//            }
//        }
    }
//    MediaPlayer {//也可用video，将mediaplayer和videooutput合在一起
//        id: mediaplayer
//        autoPlay: false
//        source: "/home/zhangzhe/Videos/"+sourcePath+".mp4"

//    }
}
}
