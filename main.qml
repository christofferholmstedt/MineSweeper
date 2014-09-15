import QtQuick 2.3
import QtQuick.Window 2.1

Window {
    id: root
    property int squareWidthAndHeight: 25
    visible: true
    height: 500
    width: 500
    color: "black"

    Grid {
        id: boardGrid
        anchors.fill: parent

        columns: Math.sqrt(boardModel.count)
        spacing: 1

        Repeater {
            id: boardGridRepeater
            model: boardModel

            delegate:
                Square {
                    id: square
                    text: number
                    height: squareWidthAndHeight
                    width: squareWidthAndHeight
            }
        }
    }
}
