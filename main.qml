import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    id: root
    property int mineWidthAndHeight: 25
    visible: true
    width: 500
    height: 500
//    width: (mineGrid.columns * mineWidthAndHeight) +
//           (mineGrid.spacing * (mineGrid.columns - 1))
//    height: width
    color: "black"

//    minimumHeight: height
//    minimumWidth: width
//    maximumHeight: height
//    maximumWidth: width

    Grid {
        id: mineGrid
        anchors.fill: parent
        columns: Math.sqrt(mineRepeater.model)
        spacing: 1

        Repeater {
            id: mineRepeater
            model: minefieldModel
            delegate: Mine {
                    id: mine
                    text: type
                    height: mineWidthAndHeight
                    width: mineWidthAndHeight
                    numberOfMines: index
                }
        }
    }

}
