import QtQuick 2.2
import QtQuick.Window 2.1

Window {
    id: root
    property int mineWidthAndHeight: 25
    visible: true
    height: 500
    width: 500
//     width: (minefieldModel.noOfMinefields * mineWidthAndHeight) +
//     (mineGrid.spacing * (minefieldModel.noOfMinefields - 1))
// height: width
    color: "black"

    minimumHeight: height
    minimumWidth: width
//    maximumHeight: height
//    maximumWidth: width

    GridView {
        id: mineGrid
        anchors.fill: parent
        model: minefieldModel
        anchors.margins: 20

        clip: true
        cellWidth: 45
        cellHeight: 45

        delegate: numberDelegate
        //columns: Math.sqrt(minefieldModel.noOfMinefields)
       // spacing: 1

//        Repeater {
//            id: mineRepeater
//            model: minefieldModel
//         delegate:  Mine {
//                id: mine
//                hasMineQml: hasMine
//                text: hasMine
//                height: mineWidthAndHeight
//                width: mineWidthAndHeight
//                numberOfMines: index
//            }
//        }
    }

    Component {
        id: numberDelegate

        Rectangle {
            width: 40
            height: 40

            color: "lightGreen"

            Text {
                anchors.centerIn: parent

                font.pixelSize: 10

                text: hasMine
            }
        }
    }
}
