import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.0
import QtQuick.Layouts 1.15
import QtGraphicalEffects 1.15

import HomePopApp 1.0

Window {
    visible: true
    flags: Qt.ToolTip | Qt.FramelessWindowHint | Qt.WA_TranslucentBackground
    color: "#00000000"
    width: homepop.mode === "800x480" ? 60: 120
    height: homepop.mode === "800x480" ? 60 : 120
    title: "Homepop"

    HomePop {
        id: homepop
        //comment
        mode: "800x480"
        is_connected: true
    }

    Image {
        id: "icon"
        source: "resources/icons/house-icon.png"
        width: homepop.mode === "800x480" ? 40: 80
        height: homepop.mode === "800x480" ? 40 : 80
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        opacity: icon.runnable ? 1 : 0.5
        property bool runnable: homepop.is_connected


        MouseArea {
            id: "mouseArea1"
            anchors.fill: parent
            onClicked: homepop.show_home()
            onPositionChanged: homepop.position_changed(mouse.x, mouse.y)
            enabled : icon.runnable
        }
    }

    BusyIndicator {
        width: homepop.mode === "800x480" ? 30: 50
        height: homepop.mode ==="800x480" ? 30 : 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        running: !homepop.is_connected
        visible: !homepop.is_connected
    }


    Rectangle {
        width: icon.width
        height: icon.height
        radius: width*0.5
        anchors.horizontalCenter: icon.horizontalCenter
        anchors.verticalCenter: icon.verticalCenter
        color: "white"
        opacity : mouseArea1.pressed === true ? 0.2 : 0
    }
}

