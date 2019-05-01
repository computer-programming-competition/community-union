import QtQuick 2.0
import VPlayApps 1.0
import VPlay 2.0
import user 1.0
import "Organization"
Page {
    id:userpage
    anchors.fill: parent
    property bool bMenuShown:false //侧边栏
    property Component settingsPage: ListPage {
        id:settingsPage
        title: "设置"
        model: [
            {text: "开启声音",detailText: "是否开启视频背景音乐",icon: IconType.volumedown},
            {text: "主题", detailText: "选择应用的主题颜色",icon: IconType.file},
        ]
        delegate: SimpleRow{
            onSelected: {
                onSettingMenu()
                userpage.settingsPage.push(modelData)
                userpage.settingsPageChanged()
            }
        }

    }



    Component{
        id:ac
        ActivityPage{

        }

    }
    GridView{

    }
    rightBarItem: IconButtonBarItem {
        icon: IconType.gears //设置
        onClicked:{
            //                    stack.popAllExceptFirstAndPush(settingsPage)
            onSettingMenu();
        }
    }
    Component {
        id: memberlist
        MemberList {}
    }


    NavigationStack{
        id:stack
        Page{
            id:stackPage

            title: "我的"

            AppImage {
                id: image
                anchors.fill: parent
                // important to automatically rotate the image taken from the camera
                autoTransform: true

                fillMode: Image.PreserveAspectFit
            }



            //头像拾取——开始
            Column{
                Row{
                    anchors.horizontalCenter: parent.horizontalCenter
                    height: userImage.height
                    spacing: dp(10)
                    width: userImage.width + spacing + choosePhotoText.width
                    UserImage {
                        id: userImage
                        property string iconFontName: Theme.iconFont.name
                        width: dp(72)
                        height: width


                        placeholderImage: "\uf007" // user
                        source: ""
                        editable: true
                        editBackgroundColor: Theme.tintColor

                        property bool shownEditPhotoDialog: false

                        onEditClicked: {
                            if (system.desktopPlatform) {
                                nativeUtils.displayImagePicker(qsTr("Choose Image"))
                            }
                            else {
                                //是否用QML更好
                                shownEditPhotoDialog = true
                                nativeUtils.displayAlertSheet("", ["本地图片", "拍照", "重置"], true)
                            }
                        }
                        Connections {
                            target: nativeUtils
                            onAlertSheetFinished: {
                                if (userImage.shownEditPhotoDialog) {
                                    if (index == 0)
                                        nativeUtils.displayImagePicker(qsTr("本地图片"))
                                    else if (index == 1)
                                        nativeUtils.displayCameraPicker("拍照")
                                    else if (index == 2)
                                        userImage.source = "" //重置
                                    userImage.shownEditPhotoDialog = false
                                }
                            }
                            onImagePickerFinished: {
                                console.debug("图片拾取结束，路径在：", path)
                                if(accepted)
                                    userImage.source = Qt.resolvedUrl(path)
                            }
                            onCameraPickerFinished: {
                                console.debug("拍照完成，路径在：", path)
                                if(accepted)
                                    userImage.source = Qt.resolvedUrl(path)
                            }
                        }
                    } //用户头像
                    AppText {
                        id: choosePhotoText
                        width: dp(130)
                        text: user.name
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: dp(12)
                        wrapMode: Text.WordWrap
                    }

                }//头像拾取——结束
                Row{
                    AppText{
                        id:personalS
                        text: user.personalS

                        //height: parent.height+250
                        font.pixelSize: dp(11)
                        //                    wrapMode: Text.WordWrap
                    }
                    AppTextInput{
                        id:personalS2
                        text: "这个人很懒，什么都没留下。"
                        //x:image.x +70
                        //height: parent.height+250
                        font.pixelSize: dp(11)
                    }
                }
            }
            Connections{
                target: nativeUtils
                onCameraPickerFinished: {//displayCamerPicker被调用，用户接受，则讲照片保存在path路径,否则保存空字符串
                    if(accepted)
                    {
                        image.source = path
                        console.log("-------------------"+path)
                    }
                }
            }
            MouseArea{
                anchors.fill:parent
                enabled: bMenuShown
                onClicked: {
                    console.log("what")
                    onSettingMenu()
                }
            }


                Row{
                    anchors.bottom: parent.bottom
                    anchors.topMargin: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 5
                    spacing: 5
                    AppButton {
                        id: button
                        z:2
                        text: "我的社团"
                        flat: false
                        radius: 90

                        //anchors.horizontalCenter: parent.horizontalCenter
                        //anchors.bottom: parent.bottom
                        //        anchors.bottomMargin: 30

                        onClicked: {
                            userpage.navigationStack.push(ac,{})
                        }
                    }
                    AppButton {
                        id: button2
                        z:2
                        text: "我的设置"
                        flat: false
                        radius: 90

                        //        anchors.horizontalCenter: parent.horizontalCenter
                        //anchors.bottom: parent.bottom
                        //        anchors.bottomMargin: 30

                        onClicked: {
                            userpage.navigationStack.push(settingsPage)
                        }

                }
                    AppButton {
                        id: button3
                        z:2
                        text: "社团管理"
                        flat: false
                        radius: 90

                        //        anchors.horizontalCenter: parent.horizontalCenter
                        //anchors.bottom: parent.bottom
                        //        anchors.bottomMargin: 30

                        onClicked: {
                            userpage.navigationStack.push(memberlist)
                        }

                }
            }

        }
    }
    Rectangle{
        id:rectangeList
        height: stackPage.height
        Behavior on width {
            NumberAnimation{
                duration: 300
            }
        }

        Column {
            id: tintColorRow
            anchors.centerIn: rectangeList
            spacing: rectangeList.spacing
            property color defaultColor: Theme.isIos ? "#007aff" : (Theme.isAndroid ? "#3f51b5" : "#01a9e2")
            property int currentIndex: 0
            visible: bMenuShown?1:0
            Connections {
                target: Theme
                onPlatformChanged: if(tintColorRow.currentIndex === 0) Theme.colors.tintColor = tintColorRow.defaultColor
            }
            AppText {
                text: "Tint:"
                anchors.verticalCenter: rectangeList.verticalCenter
            }

            Repeater {
                model: [tintColorRow.defaultColor, "#FF3B30", "#4CD964", "#FF9500","gray","black"]

                Rectangle {
                    color: modelData
                    width: dp(48)
                    height: dp(48)
                    MouseArea {
                        anchors.fill: parent
                        onClicked: { Theme.colors.tintColor =  color; tintColorRow.currentIndex = index }
                    }
                }
            }
        }

    }
    //打开侧边栏
    function onSettingMenu(){
//        menuTranslate.x = bMenuShown?0:stackPage.width*0.8
        rectangeList.width = bMenuShown?0:stackPage.width*0.8
        bMenuShown = !bMenuShown;

    }

}
