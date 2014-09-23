import QtQuick 2.3

ListModel {
    id: root
    property int rowCount: 10
    property int columnCount: 10

     Component.onCompleted: {
        for (var i = 0; i < (rowCount * columnCount); i++)
        {
            append({squareIndex: i,
                    isVisited: false,
                    noOfMines: 4,
                    hasMine: true,
                    isLocked: false})
        }
    }
}
