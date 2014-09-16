import QtQuick 2.3
import QtQuick.Window 2.1

Window {
    id: root
    property int squareWidthAndHeight: 25
    visible: true

    // boardModel.rowCount gives the total number of items in
    // underlying data structure therefore columnCount is used
    // instead and the assumption is made that the board is
    // a square and not a rectangle.
    height: (boardModel.columnCount * squareWidthAndHeight) +
            ((boardModel.columnCount * boardGrid.spacing) - 1)
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
                    text: isVisited
                    height: squareWidthAndHeight
                    width: squareWidthAndHeight
            }
        }
    }
}

