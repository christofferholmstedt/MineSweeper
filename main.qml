import QtQuick 2.3
import QtQuick.Window 2.1

Window {
    id: root
    property int squareWidthAndHeight: 25
    visible: true
    height: (boardModel.rowCount * squareWidthAndHeight) +
            ((boardModel.rowCount * boardGrid.spacing) - 1)
    width: (boardModel.columnCount * squareWidthAndHeight) +
           ((boardModel.columnCount * boardGrid.spacing) - 1)
    color: "black"

    minimumHeight: height
    minimumWidth: width
    maximumHeight: height
    maximumWidth: width

    Grid {
        id: boardGrid
        anchors.fill: parent

        columns: boardModel.columnCount
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

