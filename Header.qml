import QtQuick 2.0

Rectangle {
    width: parent.width
    height: 50
    color: "grey"

    BorderImage {
        id: menu
        source: "icons/menu.png"

        width: 30
        height: 30

        border.right: 10
        border.left: 10
        border.top: 10
        border.bottom: 10

        anchors.rightMargin: parent.right
    }
}
