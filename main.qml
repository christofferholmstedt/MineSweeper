import QtQuick 2.3
import QtQuick.Window 2.1

Window {
    id: root
    property int squareWidthAndHeight: 25
    visible: true
    height: (boardModel.rowCount * squareWidthAndHeight) + (boardModel.rowCount - 1)
    width: (boardModel.columnCount * squareWidthAndHeight) + (boardModel.columnCount - 1)
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

    function qmlDebug(a)
    {
        console.log("a is: ", a);
    }
}

