import QtQuick 2.0
import Felgo 3.0
Page {
    title:"Me"
    NavigationStack{
        Page{
            id:page
            title:"ME"

            AppButton{
                anchors.centerIn: parent
                text:"Push"
                onClicked: {
                   page.navigationStack.push(sub)
                }
            }
        }

    }
    Component{
        id:sub
        Page{
            title: "Sub"
        }
    }

}
