import QtQuick 2.12

QtObject {
    id: worker

    signal dispatched(string type, var message);

    default property alias children: worker.__children

    property list<QtObject> __children: [QtObject {}]
}
