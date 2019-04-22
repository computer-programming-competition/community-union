import VPlayApps 1.0
import QtQuick.Controls 2.2 as Quick2
import QtQuick 2.0
import QtMultimedia 5.0

Page {
    AppText {
        id: titleText
        text: "fds"
    }
    AppTextEdit {
        id: titleTextEdit
        anchors.top: titleText.bottom
        anchors.topMargin: 10
        anchors.left: titleText.left
    }
    AppText {
        id: timeText
        anchors.top: titleTextEdit.bottom
        anchors.topMargin: 10
        text: "fds"
    }
    AppTextEdit {
        id: timeTextEdit
        anchors.top: timeText.bottom
        anchors.topMargin: 10
        anchors.left: timeText.left
    }
    AppText {
        id: label
        anchors.top: timeTextEdit.bottom
        anchors.topMargin: 10
        text: "label"
    }
    AppTextEdit {
        id: labelTextEdit
        anchors.top: label.bottom
        anchors.topMargin: 10
    }

    AppText {
        id: contentText
        anchors.top: labelTextEdit.bottom
        anchors.topMargin: 20
        text: "content"
    }
    AppTextEdit {
        id: contentTextEdit
        anchors.top: contentText.bottom
        anchors.topMargin: 10
    }

    AppButton {
        id: sureButton

        text: "sure"
        flat: false
        radius: 90

        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30

        onClicked: {
            activity1_0.title = titleTextEdit.text
            activity1_0.time = timeTextEdit.text
            activity1_0.label = labelTextEdit.text
            activity1_0.content = contentTextEdit.text
            activity1_0.setNewActivity(titleTextEdit.text, timeTextEdit.text, labelTextEdit.text, contentTextEdit.text)
        }
    }
}
