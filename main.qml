import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    visible: true
    width: 360
    height: 360

    GridView {
        anchors.fill: parent
        anchors.margins: 20

        clip: true

        model: 16

        cellWidth: 51
        cellHeight: 51

        delegate: mineComponent
    }

    Component {
        id: mineComponent

        Mine {
            text: "02"
            // anchors.centerIn: parent
        }
    }
}
