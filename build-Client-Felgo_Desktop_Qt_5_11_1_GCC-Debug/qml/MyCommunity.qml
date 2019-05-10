import Felgo 3.0
import QtQuick 2.0

Page {
    id:myCommunityPage
    title: "我的社团"

    Component{
        id:mycommunityactivity
        MyCommunityActivity{

        }
    }

//    ListModel {
//        id: listMo
//        ListElement {
//            name: user.community
//        }
//    }

//    Component {
//        id: activityCo
//        Rectangle{
//            id:communitylist
//            width: myCommunityPage.width
//            height: 50
//            radius: 5
//            border.color: "gray"
//            border.width: 0.5
//            AppButton{
//                width: myCommunityPage.width
//                height: 50
//                anchors.fill: parent
//                backgroundColor: "white"
//                flat: true

//                Text {
//                    id: title
//                    font.pixelSize: sp(18)
//                    color: "black"
//                    anchors.centerIn: parent
//                    text: name
//                }
//                onClicked: {
//                    myCommunityPage.navigationStack.push(mycommunityactivity)
//                }
//            }
//        }
//    }

//    ListView {
//        anchors.fill: parent
//        model: listMo
//        delegate: activityCo
//    }

    Column{
        spacing: 10
        Rectangle{
            id:communitylist
            width: myCommunityPage.width
            height: 50
            radius: 5
            border.color: "gray"
            border.width: 0.5
            AppButton{
                width: myCommunityPage.width
                height: 50
                anchors.fill: parent
                backgroundColor: "white"
                flat: true

                Text {
                    id: title
                    font.pixelSize: sp(18)
                    color: "black"
                    anchors.centerIn: parent
                    text: user.community
                }
                onClicked: {
                    myCommunityPage.navigationStack.push(mycommunityactivity)
                }
            }
        }
    }
}
