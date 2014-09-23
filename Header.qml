import QtQuick 2.0

Rectangle {
    id: root
    width: parent.width
    height: 50
    color: "grey"

    MouseArea {
        anchors.fill: parent

        onClicked: {
            console.log("Pressed header.")
        }
    }

    Image {
        id: menu
        source: "icons/black14.png"

        width: 40
        height: 40

        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter

        MouseArea {
            anchors.fill: parent

            onClicked: {
                console.log("Pressed restart.")
            }
        }
    }

}
