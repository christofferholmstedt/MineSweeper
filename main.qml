import QtQuick 2.3
import QtQuick.Window 2.1
import QtQml 2.2

Window {
    id: root
    property int squareWidthAndHeight: 25
    visible: true

    // boardModel.rowCount gives the total number of items in
    // underlying data structure therefore columnCount is used
    // instead and the assumption is made that the board is
    // a square and not a rectangle.
    height: header.height +
            (boardModel.columnCount * squareWidthAndHeight) +
            ((boardModel.columnCount * boardGrid.spacing) - 1)
    width: (boardModel.columnCount * squareWidthAndHeight) +
           ((boardModel.columnCount * boardGrid.spacing) - 1)
    color: "black"


    signal squareClicked(int index, bool leftMouseButton)

    minimumHeight: height
    minimumWidth: width
    maximumHeight: height
    maximumWidth: width

    Column {
        spacing: 1

        Header {
            id: header
        }

        Grid {
            id: boardGrid
            objectName: "boardGrid"

            columns: boardModel.columnCount
            spacing: 1

            Repeater {
                id: boardGridRepeater
                objectName: "boardGridRepeater"
                model: boardModel

                delegate:
                    Square {
                        id: square
                        objectName: "square"
                        height: squareWidthAndHeight
                        width: squareWidthAndHeight

                        Component.onCompleted: {
                            squareClickedSignal.connect(root.squareClicked);
                            noOfMinesSquare = noOfMines;

                            // Check if the clicked square has mine or is locked.
                            if (isVisited)
                            {
                                if (hasMine)
                                {
                                    state = "hasMine";
                                }
                                else
                                {
                                    state = "hasNoMine";
                                }
                            }
                            else if (isLocked)
                            {
                                state = "locked";
                            }

                            // Check if it's game over
                            if (boardModel.isGameOver)
                            {
                                header.state = "gameOver";
                            }
                            else
                            {
                                header.state = "";
                            }
                        }

                    }

            }
        }
    }
}

