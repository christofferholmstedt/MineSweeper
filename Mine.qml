import QtQuick 2.0

Rectangle {
    property string text: "0"
    property int fontSize: 35
    property bool bold: true

    signal clicked

    id: root
    width: 50
    height: 50
    color: "#16599b"

    border.color: "#0b7e2b"
    border.width: 1

    MouseArea {
        id: mouseArea1
        x: 0
        y: 0
        width: parent.width
        height: parent.height

    }

    Text {
        id: text1
        text: root.text
        anchors.fill: parent
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: root.fontSize
    }
    states: [
        State {
            name: "pressed"

            PropertyChanges {
                target: root
                color: "#0b7e2b"
            }

        }
    ]

}
