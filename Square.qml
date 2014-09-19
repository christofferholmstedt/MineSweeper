import QtQuick 2.3

Rectangle {
    id: root
    width: 50
    height: 50
    color: "#798086"

    property int noOfMines
    property string text
    signal squareClickedSignal(int index, bool leftMouseButton)

    MouseArea {
        id: squareMouseArea
        x: 0
        y: 0
        width: parent.width
        height: parent.height

        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if (mouse.button == Qt.LeftButton)
            {
                root.squareClickedSignal(index, true);
            }
            else if (mouse.button == Qt.RightButton)
            {
                root.squareClickedSignal(index, false);
            }
            else
            {
                console.log("Error how did you click on this square?");
            }

        }
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

    states: [
        State {
            name: "base"

            PropertyChanges {
                target: root
                text: ""
                color: "#798086"
            }
        },

        State {
            name: "locked"

            PropertyChanges {
                target: root
                text: "L"
                color: "#035aa6"
            }
        },
        State {
            name: "hasMine"

            PropertyChanges {
                target: root
                text: "X"
                color: "#a9032b"
            }
        },
        State {
            name: "hasNoMine"

            PropertyChanges {
                target: root
                text: root.noOfMines
                color: "#08ae1a"
            }
        }
    ]
}
