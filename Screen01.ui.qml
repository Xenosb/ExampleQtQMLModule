import QtQuick

import ExampleLibrary
import ExampleQMLLibrary

Rectangle {
    id: root

    width: 1280
    height: 800

    color: backgroundColor

    property color backgroundColor: "white"

    SpecialButton {
        id: button

        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: label

        anchors.top: button.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 45

        text: BackendService.value
    }

    Text {
        id: label1

        anchors.top: label.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 45

        text: button.object1.value
    }

    Text {
        id: label2

        anchors.top: label1.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 45

        text: button.object2.value
    }
}
