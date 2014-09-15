import QtQuick 2.3

ListModel {
    id: root

     Component.onCompleted: {
        for (var i = 0; i<100; i++)
        {
            append({name: i})
        }
    }
}
