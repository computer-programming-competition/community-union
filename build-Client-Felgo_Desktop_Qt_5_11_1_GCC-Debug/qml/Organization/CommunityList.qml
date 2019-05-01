import VPlayApps 1.0
import QtQuick 2.0
import QtQuick.Layouts 1.1
import user 1.0
Page {
    id:communitypage
    title: "社团列表"
    property int num1: communityitem.num
    GridLayout{
        id: activityGroup
        anchors.top: activitylist.top
        anchors.topMargin: 5
        anchors.horizontalCenter: activitylist.horizontalCenter
        columnSpacing: dp(20)
        rowSpacing: dp(20)
        columns: 2
        Rectangle{
            id:activity1
            anchors.left: activityGroup.left
            anchors.leftMargin: dp(15)
            border.color: "lightgray"
            border.width: dp(1)
            width: dp(150)
            height: dp(200)
            radius: dp(6)

            Rectangle{
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width-dp(1)*2
                height: 2/3 * parent.height
                radius: dp(6)
                Image {
                    id: activity1Image
                    source: "../Image/basketball.jpg"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: dp(1)
                    width: parent.width
                    height: parent.height
                }
            }
            AppButton{
                id:activity1btn
                anchors.bottom: parent.bottom
                anchors.bottomMargin: dp(6)
                text:communityitem.nowCName(num1)
                textSize: 18
                textColor: "black"
                flat:true
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    console.debug("图片拾取结束，路径在：", num1)
                     //activityPage.number = communityitem.number
                    communitylist.navigationStack.push(activity,{number:0})
                }
            }
        }
        Component{
            id:activity
            ActivityPage{
                id:activityPage

            }
        }

        Rectangle{
            id:activity2
            anchors.left: activity1.right
            anchors.leftMargin: dp(20)
            border.color: "lightgray"
            border.width: dp(1)
            width: dp(150)
            height: dp(200)
            radius: dp(6)
            Rectangle{
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width-dp(1)*2
                height: 2/3 * parent.height
                radius: dp(6)
                Image {
                    id: activity2Image
                    source: "../Image/e-commerce.jpg"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: dp(1)
                    width: parent.width - (2 * dp(1))
                    height: parent.height
                }
            }
            AppButton{
                id:activity2btn
                anchors.bottom: parent.bottom
                anchors.bottomMargin: dp(6)
                text: communityitem.nowCName(num1+1)
                textSize: 18
                textColor: "black"
                flat:true
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {

                    //activityPage.number = num1 +1


                   console.debug("图片拾取结束，路径在：", num1)
                   communitylist.navigationStack.push(activity,{number:1})
                }
            }
        }
        Rectangle{
            id:activity3
            anchors.left: activityGroup.left
            anchors.leftMargin: dp(15)
            border.color: "lightgray"
            border.width: dp(1)
            width: dp(150)
            height: dp(200)
            radius: dp(6)
            Rectangle{
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width-dp(1)*2
                height: 2/3 * parent.height
                radius: dp(6)
                Image {
                    id: activity3Image
                    source: "../Image/hip-hop.jpg"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: dp(1)
                    width: parent.width - (2 * dp(1))
                    height: parent.height
                }
            }
            AppButton{
                id:activity3btn
                anchors.bottom: parent.bottom
                anchors.bottomMargin: dp(6)
                text: communityitem.nowCName(num1+2)
                textSize: 18
                textColor: "black"
                flat:true
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked:
                {
                    console.debug("图片拾取结束，路径在：", num1)
                   // num1++
                    communitylist.navigationStack.push(activity,{number:2})
                }
            }
        }
        Rectangle{
            id:activity4
            anchors.left: activity3.right
            anchors.leftMargin: dp(20)
            border.color: "lightgray"
            border.width: dp(1)
            width: dp(150)
            height: dp(200)
            radius: dp(6)
            Rectangle{
                anchors.top: parent.top
                anchors.horizontalCenter: parent.horizontalCenter
                width: parent.width-dp(1)*2
                height: 2/3 * parent.height
                radius: dp(6)
                Image {
                    id: activity4Image
                    source: "../Image/weiqi.jpg"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.top: parent.top
                    anchors.topMargin: dp(1)
                    width: parent.width - (2 * dp(1))
                    height: parent.height
                }
            }
            AppButton{
                id:activity4btn
                anchors.bottom: parent.bottom
                anchors.bottomMargin: dp(10)
                text: communityitem.nowCName(num1+3)
                textSize: 18
                textColor: "black"
                flat:true
                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    //communityitem.num++
                    console.debug("图片拾取结束，路径在：", num1)
                    //num1++
                    communitylist.navigationStack.push(activity,{number:3})
                }
            }
        }
    }

}




