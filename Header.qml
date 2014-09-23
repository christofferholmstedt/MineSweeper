import QtQuick 2.0

Rectangle {
    id: root
    width: parent.width
    height: 50
    color: "grey"

    property string title: ""

    Text  {
        id: title
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 5
        text: parent.title
        font.pointSize: 24
    }

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
                console.log("Pressed restart.");
                root.state = "";
            }
        }
    }

    states: [
        State {
            name: "gameOver"

            PropertyChanges {
                target: root
                title: "Game Over"
            }
       }
    ]
}
