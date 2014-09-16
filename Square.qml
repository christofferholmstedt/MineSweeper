import QtQuick 2.3

Rectangle {
    id: root
    width: 25
    height: 25
    color: "#798086"

    property string text
    signal clicked

    MouseArea {
        id: squareMouseArea
        x: 0
        y: 0
        width: parent.width
        height: parent.height
    }

    Text {
        id: squareText
        text: root.text
        anchors.fill: parent
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: root.height / 2
    }
}
