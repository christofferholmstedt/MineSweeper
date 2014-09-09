import QtQuick 2.0

Rectangle {
    property int numberOfMines
    property string text: numberOfMines.toString()
    property int fontSize
    property bool bold: true
    property bool hasMineQml

    height: 50
    width: height

    signal clicked

    id: root
    color: "#798086"

    MouseArea {
        id: mouseArea1
        x: 0
        y: 0
        width: parent.width
        height: parent.height

        onClicked: {
            console.log(hasMine.toString());
            parent.numberOfMines++;
            if (parent.numberOfMines >= 10)
            {
                root.state = "unknown";
                parent.numberOfMines = 1;
            }
            else if (parent.numberOfMines >= 7)
            {
                root.state = "foundMine";
            }
            else if (parent.numberOfMines >= 3)
            {
                root.state = "foundNoMine";
            }
            parent.text = parent.numberOfMines.toString();
        }
    }

    Text {
        id: text1
        text: root.text
        anchors.fill: parent
        font.family: "Verdana"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: root.height / 2
    }
    states: [
        State {
            id: state1
            name: "unknown"

            PropertyChanges {
                target: root
                color: "#798086"
            }
        },
        State {
            name: "foundNoMine"

            PropertyChanges {
                target: root
                color: "#1fa436"
            }

        },
        State {
            name: "foundMine"
            PropertyChanges {
                target: root
                color: "#c22b2b"
            }
        }
    ]

}
