import QtQuick
import QtQuick.Controls

import ExampleLibrary

Button {
    id: button

    text: qsTr("Press me")

    property alias object1: object1
    property alias object2: object2

    BackendObject {
        id: object1

        value: 1
    }

    BackendObject {
        id: object2

        value: 2
    }

    Connections {
        target: button

        function onClicked() {
            object1.value += 1;
            object2.value += 1;
        }
    }
}
