//guchangrong
import VPlayApps 1.0
import VPlay 2.0
import QtQuick.Controls 2.2 as Quick2
import QtQuick 2.0
import QtMultimedia 5.0
import "./Organization"

Page {
    id:certification
    title: "认证"
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
                    id: id
                    text: "社团ID"
                    x: 20
                }
                AppTextField {
                    id: idwrite
                    x: 20
                    y: 30
                    borderWidth: 0.5

                }
                AppText {
                    id: titleText
                    text: "社团名称"
                    x: 20
                }
                AppTextField {
                    id: titleTextEdit
                    x: 20
                    y: 30
                    borderWidth: 0.5

                }
            }
        }

        Component {
            id: memberlist
            MemberListAdministrator {}
        }
        Rectangle {
            width: parent.width
            height: parent.height * 0.15
            anchors.top: rectangleTop.bottom

            AppButton {
                id: sureButton

                text: "确定"
                flat: false
                radius: 90

                anchors.horizontalCenter: parent.horizontalCenter
                onClicked: {
                    client.postactivity(idwrite.text,titleTextEdit.text)


                    if(client.verifyPost)
                    {
                        certification.navigationStack.push(memberlist)
                    }else
                    {
                        console.debug("认证失败")
                    }
                }
            }
        }
    }
}
